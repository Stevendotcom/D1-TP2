#pragma once
#include "Collisions.h"

namespace Game
{

    bool Play();
    void Init(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[]);
    void Input(Structures::Player &player, bool& returnMain);
    void Update(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[], bool &playerWon,
                bool &endMatch, int &
                activeBricks);
    void Draw(Structures::Player &player, Structures::Ball &ball, Structures::Brick bricks[]);
    void DrawUI(const Structures::Player &player);
    void UpdateScore(Structures::Player &player, float currentTime);
} // namespace Game
