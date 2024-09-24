#include "Player.h"

#include "Collisions.h"
#include "GameManager.h"
#include "Structures.h"

using namespace Structures;
using namespace Sprites;

void Player::MoveRight(PlayerType &player)
{
    player.FuturePosition.X += player.Speed * GameManager::GetFrameTime();
}

void Player::MoveLeft(PlayerType &player)
{
    player.FuturePosition.X -= player.Speed * GameManager::GetFrameTime();
}


void Player::Update(PlayerType &player, const BallType &ball)
{

    if (!Collisions::DoesWallPlayer(player))
    {
        if (player.FuturePosition.X > player.Position.X)
        {
            player.Direction = Direction::Left;
        }
        else if (player.FuturePosition.X < player.Position.X)
        {
            player.Direction = Direction::Right;
        }
        else
        {
            player.Direction = Direction::Idle;
        }
        player.Position.X = player.FuturePosition.X;
    }
    Collisions::AvoidsCrushing(ball, player);
    player.FuturePosition.X = player.Position.X; // reset fpositions

}

void Player::Spawn(PlayerType &player, const Texture sprite)
{
    player.Height = HEIGHT;
    player.Width = WIDTH;
    player.Speed = SPEED;
    player.Hearts = HEARTS;
    player.Position = {static_cast<float>(SCREEN_WIDTH) / 2.0F, MARGIN + player.Height / 2.0F};
    player.FuturePosition = player.Position;
    player.Sprite = sprite;
}


void Player::Draw(PlayerType &player)
{

    SetSpriteScroll({0.13F, 1});
    SetSpriteTiling({1 / 6.0F, 1});
    switch (player.Direction)
    {
    case Direction::Left:
        player.Sprite = sprites.PlayerLeft;
        break;
    case Direction::Right:
        player.Sprite = sprites.PlayerRight;
        break;
    case Direction::Idle:
        SetSpriteTiling({1 / 2.0F, 1});
        SetSpriteScroll({0.03F, 1});
        player.Sprite = sprites.PlayerIdle;
        break;
    }
    LoadSprite(player.Sprite, player.Position, {player.Width, player.Height});
    SetSpriteTiling({1, 1});
    SetSpriteScroll({1, 1});


}
