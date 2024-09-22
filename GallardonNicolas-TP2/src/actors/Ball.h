#pragma once
#include "Collisions.h"

namespace Ball
{

    const int SPEED = 300;
    const float SPAWN_Y_HEIGTH = SCREEN_HEIGHT / 2.0f - 40.0f;
    const float RADIUS = 15.0f;

    void Spawn(Structures::Ball &ball, Texture sprite);
    void Update(Structures::Player &player, Structures::Ball &ball);
    void CollisionResult(Structures::Player &player, Structures::Ball &ball, Collisions::WhereCollides collisionPlace);
    void ChangeDirectionAfterCollision(Structures::Ball &ball, const Structures::Player &player);
    float GetWidthCollision(const Structures::Ball &ball, const Structures::Player &player);
    void Draw(Structures::Ball &ball);
};
