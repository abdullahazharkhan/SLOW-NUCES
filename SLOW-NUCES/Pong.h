#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Bat.h"
#include "AIBat.h"

class Pong
{
	public:
    static void play(int, int, std::string& game_state, int& mapIndex);
};


