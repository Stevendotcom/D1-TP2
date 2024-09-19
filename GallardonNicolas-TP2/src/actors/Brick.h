#pragma once
#include "Structures.h"

namespace Brick
{
    const int MAX_BRICKS = 20;
    const int WIDTH = 16; //todo get actual values
    const int HEIGTH = 16;


    void Generate(Structures::Brick bricks[MAX_BRICKS]);
    void Draw(Structures::Brick bricks[MAX_BRICKS]);
    void ToggleVisible(Structures::Brick &brick);
    bool DoesBrickBall(Structures::Brick bricks[Brick::MAX_BRICKS], Structures::Ball &ball);
};
