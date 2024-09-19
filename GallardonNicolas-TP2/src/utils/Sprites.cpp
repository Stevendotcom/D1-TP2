#include "Sprites.h"

#include <iostream>
#include <sl.h>

namespace Sprites
{

    Texture LoadTexture(const std::string &filename)
    {
        return slLoadTexture(filename.c_str());
    }


    void LoadSprites(Sprites &sprites)
    {

        sprites.Player = LoadTexture(ASSETS_DIR + "pathtoplayer");
        sprites.Ball = LoadTexture(ASSETS_DIR + "pathtoplayer");
        sprites.Button = LoadTexture(ASSETS_DIR + "Pixelarium/banner.png");

    }

    void SetSpriteTiling(const VectorMath::Vector2 position)
    {
        slSetSpriteTiling(position.X, position.Y);
    }


    void SetSpriteScroll(VectorMath::Vector2 position)
    {
        if (position.X > FLT_EPSILON + 1.0f && position.X < 0 && position.Y < 0 && position.Y > FLT_EPSILON + 1.0f)
        {
            std::cout << "Scroll higher than the permitted amount";
            abort();
        }
        slSetSpriteScroll(position.X, position.Y);
    }


    void LoadSprite(const Texture texture, const VectorMath::Vector2 position, VectorMath::Vector2 size)
    {
        slSprite(texture, position.X, position.Y, size.X, size.Y);
    }
}
