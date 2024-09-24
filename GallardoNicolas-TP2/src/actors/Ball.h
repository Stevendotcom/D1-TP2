#pragma once
#include "Collisions.h"

namespace Ball
{

    constexpr int SPEED = 450;
    const float SPAWN_Y_HEIGTH = SCREEN_HEIGHT / 2.0f - 40.0f;
    constexpr float RADIUS = 45.0f;

    void Spawn(Structures::Ball &ball, Texture sprite);
    void Update(const Structures::Player &player, Structures::Ball &ball);
    void CollisionResult(const Structures::Player &player, Structures::Ball &ball,
                         Collisions::WhereCollides collisionPlace);
    void ChangeDirectionAfterCollision(Structures::Ball &ball, const Structures::Player &player);
    float GetWidthCollision(const Structures::Ball &ball, const Structures::Player &player);
    void Draw(Structures::Ball &ball);
};
