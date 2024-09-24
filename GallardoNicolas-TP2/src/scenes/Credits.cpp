#include "Credits.h"

#include <sl.h>

#include "Background.h"
#include "ColorPalette.h"
#include "Fonts.h"
#include "GameManager.h"
#include "Input.h"
#include "SceneManager.h"
#include "Sprites.h"

using namespace Fonts;

void Credits::Credits()
{
    constexpr int TITLE_SIZE = 60;
    constexpr int BODY_SIZE = 30;
    constexpr float MARGIN = 70.0f;
    constexpr float BANNER_HEIGTH = 110.0F;
    constexpr VectorMath::Vector2 SIZE = {800, 200};

    while (!Input::IsKeyReleasing(SL_KEY_ENTER) && !GameManager::ShouldWindowClose())
    {

        Background::Draw();

        SetForeColor(Color::white, 1.0);
        Sprites::LoadSprite(sprites.TitleBack, {SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - BANNER_HEIGTH}, SIZE);

        SetForeColor(Color::coffee, 1.0);
        ChangeFontSize(TITLE_SIZE);
        SetFont(fonts.Title);
        TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - MARGIN - TITLE_SIZE}, "Thanks for playing!");

        ChangeFontSize(BODY_SIZE);
        SetFont(fonts.Body);
        SetForeColor(Color::dimGray, 1.0);

        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - MARGIN - TITLE_SIZE * 2.0F}, "Press Enter key to return");
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F}, "Made by Nico Gallardo!");
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 1.0F}, "Antiquity Print by SciGho");
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 2.0F}, "Dirty Harold by GGBotNet");
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 3.0F},
                  "Tiny Swords by Pixel Frog");
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 4.0F}, "Health & Stamina by Gowl");
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 5.0F}, "SimpleKeys by beamedeighth");
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 6.0F},
                  "Some Sprites were edited using SpriteFusion");
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 7.0F},
                  "Done on SIGIL engine by Geoff");
        TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 8.0F},
                  "No sheeps were harmed in the process of making this game.");

        GameManager::Render();
    }

    ChangeScene(SceneManager::Scenes::MainMenu);

}
