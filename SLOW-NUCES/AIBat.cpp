#include "AIBat.h"

AIBat::AIBat(double x, double y) : Paddle(x, y, 24)
{}

void AIBat::AIBatSpeedReverse() {
    paddleSpeed *= -1;
}