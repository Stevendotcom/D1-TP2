#include "Rules.h"

#include <sl.h>

#include "Fonts.h"
#include "GameManager.h"
#include "Input.h"
#include "Sprites.h"

using namespace Fonts;
using namespace Sprites;

void Rules::Rules()
{
    const int TITLE_SIZE = 60;
    const float MARGIN = 20.0f;
    const int BODY_SIZE = 15;

    VectorMath::Vector2 size = {20.0F, 20.0F};
    while (!Input::IsKeyReleasing(SL_KEY_ENTER) && !GameManager::ShouldWindowClose())
    {
        ChangeFontSize(TITLE_SIZE);
        SetFont(fonts.Title);
        TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - MARGIN}, "Rules");

        ChangeFontSize(BODY_SIZE);
        SetFont(fonts.Body);
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - MARGIN - TITLE_SIZE}, "Press Enter key to exit");

        TextAlignLeft();
        TextPrint({MARGIN, SCREEN_HEIGHT / 2.0F},
                  "Your objective, is to destroy the most amount of blocks possible, in the least amount of time");
        TextPrint({MARGIN, SCREEN_HEIGHT / 2.0F - BODY_SIZE}, "Controls: ");
        TextPrint({MARGIN + size.X, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 2.0F}, "To move left");
        TextPrint({MARGIN + size.X, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 3.0F}, "To move right");
        TextPrint({MARGIN + size.X, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 4.0F}, "To Pause");

        LoadSprite(sprites.LeftArrow, {MARGIN, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 2.0F}, size);
        LoadSprite(sprites.RightArrow, {MARGIN, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 3.0F}, size);
        LoadSprite(sprites.P, {MARGIN, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 4.0F}, size);
    }

}
