#include "User.h"

User::User()
{}

User::User(Resources *res): res(res)
{
	tank = Tank(res, 0);
	reset();
}

void User::reset()
{
	bulletTimer.start();
	tank.setVX(4);
	tank.setX(WINDOW_WIDTH/2);
	tank.setY(WINDOW_HEIGHT - tank.getHeight());
	flags = 5;
	name = "";
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


	if ((keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]) && (tank.getY() > WINDOW_HEIGHT / 2)){
		move += MOVE_UP;
	}
	if ((keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]) && (tank.getY() < WINDOW_HEIGHT - tank.getWidth() / 2)){
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
	
	text = name + " | ";
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
	
	
	cleanup(flags_tex, flags_tex_shadow, user_tex, user_tex_shadow);
}

