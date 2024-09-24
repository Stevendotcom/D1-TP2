#pragma once
#include "Collisions.h"

namespace Game
{
    bool Play();
    void Init(Structures::PlayerType &player, Structures::BallType &ball, Structures::BrickType bricks[]);
    void Input(Structures::PlayerType &player, bool& returnMain);
    void Update(Structures::PlayerType &player, Structures::BallType &ball, Structures::BrickType bricks[], bool &playerWon,
                bool &endMatch, int &
                activeBricks);
    void Draw(Structures::PlayerType &player, Structures::BallType &ball, Structures::BrickType bricks[], bool& rotated);
    void DrawUI(const Structures::PlayerType &player);
    void UpdateScore(Structures::PlayerType &player, float currentTime);
} // namespace Game
