#pragma once
#include "Wrapper.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

namespace Player
{
    const int MARGIN = 10;
    const int SPEED = 600;
    const int WIDTH = 25;
    const int HEIGHT = 150;

    enum class WhereCollides
    {
        Up,
        Left,
        Right,
        None
    };
    struct Key
    {
        int Left;
        int Right;
    };

    struct Player
    {
        VectorMath::Vector2 Position;
        VectorMath::Vector2 FuturePosition;
        Wrapper::Texture Sprite;
        Key Keys;
        float Direction;
        int Width;
        int Height;
        int Speed;
        int Score;
    };


    void MoveRight(Player &player);
    void MoveLeft(Player &player);
    bool DoesCollide(Player &player);
    void Update(Player &p1);
    void Spawn(Player &player, Wrapper::Texture sprite);
} 
