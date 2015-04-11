#include "Game.h"

Game::Game()
{
	// Initialize SDL2
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	
	// Create an application window with the following settings:
	res.screen = SDL_CreateWindow(
		WINDOW_CAPTION,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_OPENGL
	);

	// Check that the window was successfully made
	if (res.screen == NULL) {
		// In the event that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return;
	}
	
	res.renderer = SDL_CreateRenderer(res.screen, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	const std::string resPath = getResourcePath();
	
	res.sprites_txt = loadTexture(resPath + "sheet_tanks.png", res.renderer);
	res.andy_fnt = loadFont(resPath + "androidnation.ttf", 30);
	res.andy_fnt_min = loadFont(resPath + "androidnation.ttf", 15);
	
    StateStack.push(2); // Exit
    StateStack.push(0); // menu
	
	user = User(&res);
	
	enemyGenerateTimer.start();
	
	res.prompt_tex = renderText("Please input your name:", res.andy_fnt_min, res.white_clr, res.renderer);
	res.continue_tex = renderText("Press (Enter) to continue...", res.andy_fnt_min, res.white_clr, res.renderer);

}

Game::~Game()
{
	// Clean up
	cleanup(res.andy_fnt_min, res.andy_fnt, res.sprites_txt, res.renderer, res.screen);
	cleanup(res.prompt_tex, res.continue_tex);
	enemies.clear();
    TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Game::Run()
{
	// Our game loop is just a while loop that breaks when our state stack is empty.
	while (!StateStack.empty())
	{
		res.timeDelta = (BASE_TIME - res.timeDeltaTimer.getTicks());
		
		switch(StateStack.top()){
			case 0:
				StartMenu();
				break;
			
			case 1:
				Play();
				break;
			
			case 2:
				Exit();
				break;
			
			case 3:
				InputNameMenu();
				break;
		}
		
		res.timeDeltaTimer.start();
	}
}


// This function handles the game's main menu. From here 
// the player can select to enter the game, or quit. 
void Game::StartMenu()
{
	HandleStartMenuInput();

	// Make sure nothing from the last frame is still drawn.
	SDL_RenderClear(res.renderer);

	SDL_Texture *start_tex = renderText("Start (G)ame", res.andy_fnt, res.white_clr, res.renderer);
	SDL_Texture *quit_tex = renderText("(Q)uit Game", res.andy_fnt, res.white_clr, res.renderer);

	int w, h;

	SDL_QueryTexture(start_tex, NULL, NULL, &w, &h);
	renderTexture(start_tex, res.renderer, (WINDOW_WIDTH - w) / 2, (WINDOW_HEIGHT - h) / 2 - 40);

	SDL_QueryTexture(quit_tex, NULL, NULL, &w, &h);
	renderTexture(quit_tex, res.renderer, (WINDOW_WIDTH - w) / 2, (WINDOW_HEIGHT - h) / 2);

	SDL_RenderPresent(res.renderer);

	cleanup(start_tex, quit_tex);

}


void Game::InputNameMenu()
{
	int w, h;
	static Timer blinker;
	static bool blink = true;
	
	// Make sure nothing from the last frame is still drawn.
	SDL_RenderClear(res.renderer);

	if (SDL_PollEvent(&res.event)) {
		switch (res.event.type) {
			case SDL_KEYDOWN:
			   //Handle backspace
				if(res.event.key.keysym.sym == SDLK_BACKSPACE && res.text.length() > 0 )
				{
					//lop off character
					res.text.pop_back();
				}
				//Handle copy
				else if(res.event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
				{
					SDL_SetClipboardText(res.text.c_str());
				}
				//Handle paste
				else if(res.event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
				{
					res.text = SDL_GetClipboardText();
				}
				else if(res.event.key.keysym.sym == SDLK_RETURN)
				{
					StateStack.pop();
					StateStack.push(1); // Game
					SDL_StopTextInput();
					res.text = "";
					blinker.stop();
				}
				break;

			case SDL_QUIT:
				// While state stack isn't empty, pop 
				while (!StateStack.empty())
				{
					StateStack.pop();
				}
				res.text = "";
				SDL_StopTextInput();
				blinker.stop();
				
				break;
			case SDL_TEXTINPUT:
			   //Not copy or pasting
				if	(!((res.event.text.text[ 0 ] == 'c' || res.event.text.text[ 0 ] == 'C' ) && 
					   (res.event.text.text[ 0 ] == 'v' || res.event.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ))
				{
					//Append character
					res.text += res.event.text.text;
				}
				break;
		}
	}
	
	SDL_Texture *temp_tex;
	
	if (!blinker.isStarted()){
		blinker.start();
		SDL_StartTextInput();
	} else if (blinker.getTicks() > res.timeDelta){
		blink = !blink;
		blinker.start();
	}
	temp_tex = renderText(blink ? res.text + "_": res.text + "  ", res.andy_fnt, res.white_clr, res.renderer);
	
	SDL_QueryTexture(res.prompt_tex, NULL, NULL, &w, &h);
	renderTexture(res.prompt_tex, res.renderer, (WINDOW_WIDTH - w) / 2, (WINDOW_HEIGHT - h) / 2 - 80);

	SDL_QueryTexture(temp_tex, NULL, NULL, &w, &h);
	renderTexture(temp_tex, res.renderer, (WINDOW_WIDTH - w) / 2, (WINDOW_HEIGHT - h) / 2);
	
	SDL_QueryTexture(res.continue_tex, NULL, NULL, &w, &h);
	renderTexture(res.continue_tex, res.renderer, (WINDOW_WIDTH - w) / 2, (WINDOW_HEIGHT - h) / 2 + 80);

	SDL_RenderPresent(res.renderer);
	
	cleanup(temp_tex);
}


// This function handles the main game. We'll control the
// drawing of the game as well as any necessary game logic. 
void Game::Play()
{
	enemyGenerate();
	
	HandlePlayInput();
	user.update();
	
	for (auto enemy = begin (enemies); enemy != end (enemies);) {
		enemy->update();
		
		if (enemy->getY() > WINDOW_HEIGHT - 100){
			enemy = enemies.erase(enemy);
		} else {
			++enemy;
		}
	}

	SDL_RenderClear(res.renderer);
	
	
//	back.draw(renderer);
	user.draw();
	for (Enemy & enemy : enemies) {
		enemy.draw();
	}

	SDL_RenderPresent(res.renderer);

}

// This function handles the game's exit screen. It will display 
// a message asking if the player really wants to quit.
void Game::Exit()
{     
	HandleExitInput();

	// Make sure nothing from the last frame is still drawn.
	SDL_RenderClear(res.renderer);

	
	SDL_Texture *quit_tex = renderText("Quit Game (Y or N)?", res.andy_fnt, res.white_clr, res.renderer);
	
	int w, h;
	
	SDL_QueryTexture(quit_tex, NULL, NULL, &w, &h);
	renderTexture(quit_tex, res.renderer, (WINDOW_WIDTH - w) / 2, (WINDOW_HEIGHT - h) / 2);

	SDL_RenderPresent(res.renderer);

	cleanup(quit_tex);
}


// This function receives player input and 
// handles it for the game's menu screen. 
void Game::HandleStartMenuInput() 
{
    // Fill our event structure with event information. 
    if ( SDL_PollEvent(&res.event) )
    {
        // Handle user manually closing game window 
        if (res.event.type == SDL_QUIT)
        { 
            // While state stack isn't empty, pop 
            while (!StateStack.empty())
            {
                StateStack.pop();
            }

            return; // game is over, exit the function
        }

        // Handle keyboard input here 
        if (res.event.type == SDL_KEYDOWN)
        {
            if (res.event.key.keysym.sym == SDLK_ESCAPE)
            {
                StateStack.pop();
                return; // this state is done, exit the function 
            }
            // Quit 
            if (res.event.key.keysym.sym == SDLK_q)
            {
                StateStack.pop();
                return; // game is over, exit the function 
            }
            // Start Game 
            if (res.event.key.keysym.sym == SDLK_g)
            {
                StateStack.push(3); // Name Input
                return; // this state is done, exit the function 
            }
        }
    }
}

// This function receives player input and 
// handles it for the main game state. 
void Game::HandlePlayInput() 
{
    // Fill our event structure with event information.
    if ( SDL_PollEvent(&res.event) )
    {
        // Handle user manually closing game window
        if (res.event.type == SDL_QUIT)
        { 
            // While state stack isn't empty, pop 
            while (!StateStack.empty())
            {
                StateStack.pop();
            }

            return; // game is over, exit the function
        }

        // Handle keyboard input here 
        if (res.event.type == SDL_KEYDOWN)
        {
            if (res.event.key.keysym.sym == SDLK_ESCAPE)
            {
                StateStack.pop();

                return; // this state is done, exit the function 
            }
        }
		
    }
}

// This function receives player input and 
// handles it for the game's exit screen.
void Game::HandleExitInput() 
{
    // Fill our event structure with event information. 
    if ( SDL_PollEvent(&res.event) )
    {
        // Handle user manually closing game window
        if (res.event.type == SDL_QUIT)
        { 
            // While state stack isn't empty, pop
            while (!StateStack.empty())
            {
                StateStack.pop();
            }

            return; // game is over, exit the function
        }

        // Handle keyboard input here 
        if (res.event.type == SDL_KEYDOWN)
        {
            if (res.event.key.keysym.sym == SDLK_ESCAPE)
            {
                StateStack.pop();

                return; // this state is done, exit the function 
            }
            // Yes 
            if (res.event.key.keysym.sym == SDLK_y)
            {
                StateStack.pop();
                return; // game is over, exit the function 
            }
            // No 
            if (res.event.key.keysym.sym == SDLK_n)
            {
                StateStack.push(0); // Menu
                return; // this state is done, exit the function 
            }
        }
    }
}

void Game::enemyGenerate()
{
	static float location = WINDOW_WIDTH / 2;
	static int location_step = random(1, 3);
	static int type = random(1, 5);
	static int type_step = random(1, 3);
	
	static int nextTime = 2;

	if (enemyGenerateTimer.getTicks() >= res.timeDelta * nextTime){
		type_step--;
		location_step--;
		
		nextTime = random(2, 4);
		
		if (type_step == 0)
		{
			type = random(1, 4);
			std::cout<<type<<std::endl;
			type_step = random(1, 8);
		}
		
		Enemy enemy = Enemy(&res, type);
		
		if (location_step == 0){
			location = random(enemy.getWidth()/2, WINDOW_WIDTH - enemy.getWidth()/2);
			location_step = random(1, 3);
		}
		enemy.setX(location);
		
		enemies.push_back(enemy);
		
		enemyGenerateTimer.start();
	}
	

}