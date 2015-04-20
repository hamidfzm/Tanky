#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stack>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>

// Constants
#include "Defines.h"

// Game Tools
#include "Utils.h"
#include "Path.h"
#include "Cleanup.h"
#include "Timer.h"
#include "Resources.h"

// Game
#include "User.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Tile.h"

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
	Tile tile;
	std::vector<Enemy> enemies;
	std::vector<Bullet> bullets;
	
	// Functions to handle the three states of the game 
	void StartMenu();
	void PauseMenu();
	void InputNameMenu();
	void ScoresMenu();

	void Play();
	void Exit();

	void HandleStartMenuInput();
	void HandlePauseMenuInput();
	void HandleScoresMenuInput();
	void HandlePlayInput();
	void HandleExitInput();

	Timer enemyGenerateTimer;
	void enemyGenerate();
	void Reset();

	std::map<std::string, int> players;
};

#endif // GAME_H
