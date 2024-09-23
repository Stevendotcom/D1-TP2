﻿#pragma once
#include "Sprites.h"
#include "VectorMath.h"

namespace Structures
{
    enum class Powers
    {
        None
    };

    struct Ball
    {
        VectorMath::Vector2 Position;
        VectorMath::Vector2 FuturePosition;
        VectorMath::Vector2 Direction;
        Texture Sprite;
        float Radius;
        float Speed;
    };
    enum class Direction
    {
        Left,
        Right,
        Idle,
        Hit
    };
    struct Player
    {
        VectorMath::Vector2 Position;
        VectorMath::Vector2 FuturePosition;
        Direction Direction;
        Texture Sprite;
        float Width;
        float Height;
        int Speed;
        int Score;
        int Hearts;
    };

    struct Brick
    {
        Powers Power;
        bool IsVisible;
        VectorMath::Vector2 Position;
        VectorMath::Vector2 Size;
        Texture Sprite;
    };
}
