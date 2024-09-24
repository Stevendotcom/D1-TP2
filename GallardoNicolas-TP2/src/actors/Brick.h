#pragma once
#include "Structures.h"

namespace Brick
{
    constexpr int MAX_BRICKS = 20;

    void Generate(Structures::Brick bricks[MAX_BRICKS]);
    void Draw(Structures::Brick bricks[MAX_BRICKS]);
    void ToggleVisible(Structures::Brick &brick);
    bool Update(Structures::Brick bricks[MAX_BRICKS], Structures::Ball &ball, int &activeBricks);
    void ActivatePower(Structures::Brick &brick);
};
