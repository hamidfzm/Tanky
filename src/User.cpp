#include "User.h"

User::User()
{}

User::User(Resources *res): res(res)
{
	tank = Tank(res, 0);
	fuel_box.x = 10;
	fuel_box.y = WINDOW_HEIGHT - 20;
	fuel_box.w = WINDOW_WIDTH - 20;
	fuel_box.h = 10;
	
	fuel_box_outline.x = 9;
	fuel_box_outline.y = WINDOW_HEIGHT - 21;
	fuel_box_outline.w = WINDOW_WIDTH - 18;
	fuel_box_outline.h = 12;
	
	reset();
}

void User::reset()
{
	bulletTimer.start();
	fuelTimer.start();
	tank.setVX(4);
	tank.setX(WINDOW_WIDTH/2);
	tank.setY(WINDOW_HEIGHT - tank.getHeight());
	fuel_box.w = WINDOW_WIDTH - 20;
	flags = 5;
	name = "";
	score = 0;
	fuel = 1000;
	fuel_clr.r = 110;
	fuel_clr.g = 255;
	fuel_clr.b = 0;
	fuel_clr.a = 0;
}

float User::getX()
{
	return tank.getX();
}

float User::getY()
{
	return tank.getY();
}

float User::getBarrelHead()
{
	return tank.getBarrelHead();
}

void User::update()
{
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);
	int move = 0;


	if ((keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]) && (tank.getY() > WINDOW_HEIGHT / 2 - 15)){
		move += MOVE_UP;
	}
	if ((keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]) && (tank.getY() < WINDOW_HEIGHT - tank.getHeight() / 2 - 30)){
		move += MOVE_DOWN;
	}
	if ((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A] ) && (tank.getX() > tank.getWidth() / 2)){
		move += MOVE_LEFT;
	}
	if ((keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) && (tank.getX() < WINDOW_WIDTH - tank.getWidth() / 2)){
		move += MOVE_RIGHT;
	}
	if (keystates[SDL_SCANCODE_SPACE] &&  bulletTimer.getTicks() > res->timeDelta){
		fired = true;
		bulletTimer.start();
		tank.fire();
		
	} else {
		fired = false;
	}
	
	tank.move(move);
	
	if (fuel > 0){
		fuel -= 300 / res->timeDelta;
	} else {
		fuel = 0;
	}
	
	
}

bool User::isFired()
{
	return fired;
}

void User::draw()
{
	std::string text = "Flags: " + std::to_string(flags);
	SDL_Texture *flags_tex = renderText(text, res->andy_fnt_min, res->white_clr, res->renderer);
	SDL_Texture *flags_tex_shadow = renderText(text, res->andy_fnt_min, res->black_clr, res->renderer);
	
	text = name + " | " + std::to_string(score);
	SDL_Texture *user_tex = renderText(text, res->andy_fnt_min, res->white_clr, res->renderer);
	SDL_Texture *user_tex_shadow = renderText(text, res->andy_fnt_min, res->black_clr, res->renderer);
	
	int w;
	SDL_QueryTexture(flags_tex, NULL, NULL, &w, NULL);
	renderTexture(flags_tex_shadow, res->renderer, WINDOW_WIDTH - w - 2, 6);
	renderTexture(flags_tex, res->renderer, WINDOW_WIDTH - w - 3, 5);
	
	SDL_QueryTexture(user_tex, NULL, NULL, &w, NULL);
	renderTexture(user_tex_shadow, res->renderer, 2, 6);
	renderTexture(user_tex, res->renderer, 3, 5);
	
	tank.draw();

	SDL_RenderFillRect(res->renderer, &fuel_box_outline);
	
    // Set render color to blue ( rect will be rendered in this color )
	fuel_clr.g = ((255 * fuel) / FUEL);
	fuel_clr.r = fuel_clr.g - 145;
    SDL_SetRenderDrawColor(res->renderer, fuel_clr.r, fuel_clr.g, fuel_clr.b, fuel_clr.a);
	
    // Render rect
	fuel_box.w = ((WINDOW_WIDTH - 20) * fuel) / FUEL;
    SDL_RenderFillRect(res->renderer, &fuel_box);
	
	SDL_SetRenderDrawColor(res->renderer, 0, 0, 0, 0);
	
	cleanup(flags_tex, flags_tex_shadow, user_tex, user_tex_shadow);
}

