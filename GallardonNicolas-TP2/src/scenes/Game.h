#pragma once
#include "Collisions.h"

namespace Game
{

    bool Play();
    void Init(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[]);
    void Input(Structures::Player &player);
    void Update(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[], bool& playerWon, bool& endMatch);
    void Draw(Structures::Player& player, Structures::Ball& ball, Structures::Brick bricks[]);
    void DrawUI(const Structures::Player& player);
    int UpdateScore(Structures::Player &player, float time, int activeBricks);
} // namespace Game
