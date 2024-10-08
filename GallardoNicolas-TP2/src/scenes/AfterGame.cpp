#include "AfterGame.h"

#include <sl.h>

#include "Background.h"
#include "ColorPalette.h"
#include "Fonts.h"
#include "GameManager.h"
#include "Input.h"
#include "SceneManager.h"
#include "Sprites.h"


void PlayerWon::AfterScene(const bool playerWon)
{
    using namespace Fonts;

    while (!Input::IsKeyReleasing(SL_KEY_ENTER) && !GameManager::ShouldWindowClose())
    {
        constexpr int TITLE_SIZE = 40;
        constexpr int BODY_SIZE = 20;
        constexpr VectorMath::Vector2 SIZE = {800, 200};
        Background::Draw();

        Sprites::LoadSprite(sprites.TitleBack, {SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F}, SIZE);
        std::string text;

        if (playerWon)
        {
            text = "You Won! Thanks for playing!";
        }
        else
        {
            text = "Oh no! You lost";
        }
        SetForeColor(Color::COFFEE, 1.0);
        ChangeFontSize(TITLE_SIZE);
        SetFont(fonts.Title);
        TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F}, text);

        SetForeColor(Color::DIM_GRAY, 1.0);
        ChangeFontSize(BODY_SIZE);
        SetFont(fonts.Body);
        TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F - TITLE_SIZE}, "Press enter key to continue");

        GameManager::Render();

    }
    ChangeScene(SceneManager::Scenes::MainMenu);
}
