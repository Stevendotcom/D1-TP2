#include "Player.h"
#include "Collisions.h"
#include "GameManager.h"
#include "Structures.h"


void Player::MoveRight(Structures::Player &player)
{
    player.FuturePosition.X += player.Speed * GameManager::GetFrameTime();
}

void Player::MoveLeft(Structures::Player &player)
{
    player.FuturePosition.X -= player.Speed * GameManager::GetFrameTime();
}


void Player::Update(Structures::Player &player)
{
    if (!Collisions::DoesWallPlayer(player))
    {
        player.Position.X = player.FuturePosition.X;
    }
    player.FuturePosition.X = player.Position.X; // reset fpositions

}

void Player::Spawn(Structures::Player &player, Texture sprite)
{
    player.Height = HEIGHT;
    player.Width = WIDTH;
    player.Speed = SPEED;
    player.Hearts = HEARTS;
    player.Position = {static_cast<float>(SCREEN_WIDTH) / 2.0F, MARGIN};
    player.FuturePosition = player.Position;
    player.Sprite = sprite;
}
