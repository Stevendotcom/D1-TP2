#pragma once
#include "Collisions.h"

namespace Ball
{

    constexpr int SPEED = 450;
    const float SPAWN_Y_HEIGTH = SCREEN_HEIGHT / 2.0f - 40.0f;
    constexpr float RADIUS = 45.0f;

    void Spawn(Structures::BallType &ball, Texture sprite);
    void Update(const Structures::PlayerType &player, Structures::BallType &ball);
    void CollisionResult(const Structures::PlayerType &player, Structures::BallType &ball,
                         Collisions::WhereCollides collisionPlace);
    void ChangeDirectionAfterCollision(Structures::BallType &ball, const Structures::PlayerType &player);
    float GetWidthCollision(const Structures::BallType &ball, const Structures::PlayerType &player);
    void Draw(Structures::BallType &ball);
};
