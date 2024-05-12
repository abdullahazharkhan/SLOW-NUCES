#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include "Paddle.h"

class AIBat : public Paddle
{

public:
    AIBat(double x, double y);
    void AIBatSpeedReverse();
};