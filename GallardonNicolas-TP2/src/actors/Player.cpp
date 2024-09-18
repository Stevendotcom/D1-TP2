#include "Player.h"

#include <cfloat>

// definitions

void Player::MoveRight(Player &player)
{
    player.FuturePosition.X += player.Speed * Wrapper::GetFrameTime();
}

void Player::MoveLeft(Player &player)
{
    player.FuturePosition.X -= player.Speed * Wrapper::GetFrameTime();
}

bool Player::DoesCollide(Player &player)
{
    return player.FuturePosition.X <= FLT_EPSILON ||
        player.FuturePosition.X >= static_cast<float>(SCREEN_HEIGHT - player.Width) - FLT_EPSILON;
}

void Player::Update(Player &p1)
{
    if (!DoesCollide(p1))
    {
        p1.Position.X = p1.FuturePosition.X;
    }
    p1.FuturePosition.X = p1.Position.X; // reset fpositions

}

void Player::Spawn(Player &player, Wrapper::Texture sprite)
{
    player.Height = HEIGHT;
    player.Width = WIDTH;
    player.Speed = SPEED;
    player.Position = {static_cast<float>(SCREEN_WIDTH) / 2.0f, MARGIN};
    player.FuturePosition = player.Position;
    player.Sprite = sprite;
}
