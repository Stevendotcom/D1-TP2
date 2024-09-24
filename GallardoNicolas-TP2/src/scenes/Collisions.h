#pragma once
#include "Structures.h"

namespace Collisions
{
    constexpr int MARGIN = 50;
    constexpr float LEFT = MARGIN;
    const float RIGHT = SCREEN_WIDTH - MARGIN;
    const float UP = SCREEN_HEIGHT - MARGIN;

    enum class WhereCollides
    {
        Up,
        Down,
        Left,
        Right,
        None
    };


    bool DoesWallPlayer(const Structures::PlayerType &player);
    bool DoesWallBall(const Structures::BallType &ball, WhereCollides &collisionPlace);
    bool DoesAABB(const VectorMath::Vector2 &position, const VectorMath::Vector2 &size,
                  const Structures::BallType &ball, WhereCollides &collisionPlace);
    void AvoidsCrushing(const Structures::BallType &ball, Structures::PlayerType &player);
};
