#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include "Paddle.h"

class Bat : public Paddle
{
public:
    Bat(double x, double y);
};