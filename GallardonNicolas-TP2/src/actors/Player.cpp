#include "Player.h"
#include "Collisions.h"
#include "Structures.h"
#include "Wrapper.h"

// definitions

void Player::MoveRight(Structures::Player &player)
{
    player.FuturePosition.X += player.Speed * Wrapper::GetFrameTime();
}

void Player::MoveLeft(Structures::Player &player)
{
    player.FuturePosition.X -= player.Speed * Wrapper::GetFrameTime();
}


void Player::Update(Structures::Player &p1)
{
    if (!Collisions::DoesWallPlayer(p1))
    {
        p1.Position.X = p1.FuturePosition.X;
    }
    p1.FuturePosition.X = p1.Position.X; // reset fpositions

}

void Player::Spawn(Structures::Player &player, Wrapper::Texture sprite)
{
    player.Height = HEIGHT;
    player.Width = WIDTH;
    player.Speed = SPEED;
    player.Position = {static_cast<float>(SCREEN_WIDTH) / 2.0F, MARGIN};
    player.FuturePosition = player.Position;
    player.Sprite = sprite;
}
