#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stack>
#include <vector>

// Constants
#include "Defines.h"

// Game Tools
#include "Utils.h"
#include "Path.h"
#include "Cleanup.h"
#include "Timer.h"
#include "Resources.h"

#include "User.h"
#include "Enemy.h"

class Game
{
public:
	Game();
	~Game();
	void Run();


private:
	std::stack<int> StateStack;    // Our state stack
	
	Resources res;
	User user;
	std::vector<Enemy> enemies;
	
	// Functions to handle the three states of the game 
	void StartMenu();
	void InputNameMenu();
	void Scoresmenu();

	void Play();
	void Exit();

	void HandleStartMenuInput();
	void HandlePlayInput();
	void HandleExitInput();

	Timer enemyGenerateTimer;
	void enemyGenerate();

};

#endif // GAME_H
