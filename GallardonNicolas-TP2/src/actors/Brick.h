#pragma once
#include "Structures.h"

namespace Brick
{
    const int MAX_BRICKS = 20;


    void Generate(Structures::Brick bricks[MAX_BRICKS]);
    void Draw(Structures::Brick bricks[MAX_BRICKS]);
    void ToggleVisible(Structures::Brick &brick);
    int Update(Structures::Brick bricks[MAX_BRICKS], Structures::Ball &ball);
    void ActivatePower(Structures::Brick &brick);
};
