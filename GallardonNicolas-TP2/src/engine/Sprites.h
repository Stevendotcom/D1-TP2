﻿#pragma once
#include <string>

#include "VectorMath.h"

typedef int Texture;

namespace Sprites
{
    struct Sprites
    {
        Texture Player;
        Texture Ball;
        Texture Button;
        Texture HeartsBorder;
        Texture Heart;
    };

    void LoadSprites(Sprites &sprites);
    Texture LoadTexture(const std::string &filename);
    void SetSpriteTiling(VectorMath::Vector2 position);
    void SetSpriteScroll(VectorMath::Vector2 position);
    void LoadSprite(Texture texture, VectorMath::Vector2 position, VectorMath::Vector2 size);
};

extern Sprites::Sprites sprites;
