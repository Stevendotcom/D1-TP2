#pragma once
#include "Wrapper.h"
#include "VectorMath.h"

namespace Brick
{
    const int MAX_BRICKS = 20;
    const int WIDTH = 16; //todo get actual values
    const int HEIGTH = 16;
    enum class Powers
    {
        // None = LoadTexture(...);
        None
    };
    struct Brick
    {
        Powers Power;
        bool IsVisible;
        VectorMath::Vector2 Position;
        VectorMath::Vector2 Size;
        Wrapper::Texture Sprite = static_cast<Wrapper::Texture>(Power);
    };

    void Draw(Brick bricks[MAX_BRICKS]);
    void ToggleVisible(Brick& brick);
    //bool DoesCollide(Brick bricks[MAX_BRICKS]);

};
