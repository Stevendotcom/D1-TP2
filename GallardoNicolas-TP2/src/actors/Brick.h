#pragma once
#include "Structures.h"

namespace Brick
{
    constexpr int MAX_BRICKS = 20;

    void Generate(Structures::BrickType bricks[MAX_BRICKS]);
    void Draw(Structures::BrickType bricks[MAX_BRICKS]);
    void ToggleVisible(Structures::BrickType &brick);
    bool Update(Structures::BrickType bricks[MAX_BRICKS], Structures::BallType &ball, int &activeBricks);
    void ActivatePower(const Structures::BrickType &brick);
    Structures::SpecialBricks GetActivePower();
    void SetActivePower(const Structures::SpecialBricks& power);
};
