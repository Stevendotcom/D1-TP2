#pragma once
#include <string>

#include "VectorMath.h"

typedef int Texture;

namespace Sprites
{
    struct Sprites
    {
        Texture PlayerLeft;
        Texture PlayerRight;
        Texture PlayerIdle;
        Texture Grass;
        Texture Background;
        Texture Ball;
        Texture Button;
        Texture HeartsBorder;
        Texture Heart;
        Texture LeftArrow;
        Texture RightArrow;
        Texture P;
        Texture TitleBack;
        Texture Faster;
        Texture Invert;
        Texture OneUp;
        Texture Rotate;
        Texture ScoreBack;

    };

    void LoadSprites(Sprites &sprites);
    Texture LoadTexture(const std::string &filename);
    void SetSpriteTiling(VectorMath::Vector2 position);
    void SetSpriteScroll(VectorMath::Vector2 position);
    void LoadSprite(Texture texture, VectorMath::Vector2 position, VectorMath::Vector2 size);
    void Rotate(float angle);
    void Translate(const VectorMath::Vector2& position);
};

extern Sprites::Sprites sprites;
