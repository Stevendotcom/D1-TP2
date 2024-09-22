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
    player.Position = {static_cast<float>(SCREEN_WIDTH) / 2.0F, MARGIN + player.Height / 2.0F};
    player.FuturePosition = player.Position;
    player.Sprite = sprite;
}


void Player::Draw(Structures::Player &player, Direction direction)
{

    switch (direction)
    {
    case Direction::Left:
        player.Sprite = sprites.PlayerLeft;
        Sprites::SetSpriteTiling({1 / 6.0F, 1});
        break;
    case Direction::Right:
        player.Sprite = sprites.PlayerRight;
        break;
    case Direction::Idle:
        player.Sprite = sprites.PlayerIdle;
        break;
    case Direction::Hit:
        player.Sprite = sprites.PlayerHit;
        break;
    }
    Sprites::SetSpriteScroll({0.13F,1});
    Sprites::LoadSprite(player.Sprite, player.Position, {player.Width, player.Height});
    Sprites::SetSpriteTiling({1, 1});
    Sprites::SetSpriteScroll({1,1});


}
