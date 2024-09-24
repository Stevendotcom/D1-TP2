#include "Rules.h"

#include <sl.h>

#include "Background.h"
#include "ColorPalette.h"
#include "Fonts.h"
#include "GameManager.h"
#include "Input.h"
#include "SceneManager.h"
#include "Shapes.h"
#include "Sprites.h"

using namespace Fonts;
using namespace Sprites;

void Rules::Rules()
{
    const int TITLE_SIZE = 60;
    const int BODY_SIZE = 30;
    const float MARGIN_Y = 40.0f;
    const float MARGIN_X = 90.0f;
    const float ALIGN = 10.0F;

    VectorMath::Vector2 size = {40.0F, 40.0F};
    while (!Input::IsKeyReleasing(SL_KEY_ENTER) && !GameManager::ShouldWindowClose())
    {
        Background::Draw();

        Color::SetForeColor(Color::coffee,1);

        ChangeFontSize(TITLE_SIZE);
        CenterText();
        SetFont(fonts.Title);
        TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - MARGIN_Y - TITLE_SIZE}, "Rules");

        Color::SetForeColor(Color::dimGray,1);

        ChangeFontSize(BODY_SIZE);
        SetFont(fonts.Body);
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - MARGIN_Y - TITLE_SIZE - BODY_SIZE}, "Press Enter key to return");

        TextAlignLeft();
        TextPrint({MARGIN_X, SCREEN_HEIGHT / 2.0F},
                  "Your objective, is to destroy the most amount of blocks possible, \nin the least amount of time");
        TextPrint({MARGIN_X, SCREEN_HEIGHT / 2.0F - BODY_SIZE - MARGIN_Y}, "Controls: ");
        TextPrint({MARGIN_X + size.X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y) * 2.0F}, "To move left");
        TextPrint({MARGIN_X + size.X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y) * 3.0F}, "To move right");
        TextPrint({MARGIN_X + size.X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y) * 4.0F}, "To Pause");

        Color::SetForeColor(Color::white,1);

        LoadSprite(sprites.LeftArrow, {MARGIN_X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y) * 2.0F + ALIGN}, size);
        LoadSprite(sprites.RightArrow, {MARGIN_X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y) * 3.0F + ALIGN}, size);
        LoadSprite(sprites.P, {MARGIN_X, SCREEN_HEIGHT / 2.0F - (BODY_SIZE + MARGIN_Y) * 4.0F + ALIGN}, size);

        GameManager::Render();

    }
    ChangeScene(SceneManager::Scenes::MainMenu);

}
