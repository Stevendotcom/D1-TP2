#include "AfterGame.h"

#include <sl.h>

#include "Background.h"
#include "ColorPalette.h"
#include "Fonts.h"
#include "GameManager.h"
#include "Input.h"
#include "SceneManager.h"


void PlayerWon::AfterScene(const bool playerWon)
{
    while (!Input::IsKeyReleasing(SL_KEY_ENTER) && !GameManager::ShouldWindowClose())
    {
        const int TITLE_SIZE = 40;
        const int BODY_SIZE = 20;

        Background::Draw();

        std::string text;

        if (playerWon)
        {
            text = "You Won! Thanks for playing!";
        }
        else
        {
            text = "Oh no! You lost";
        }
        SetForeColor(Color::coffee, 1.0);
        Fonts::ChangeFontSize(TITLE_SIZE);
        Fonts::SetFont(fonts.Title);
        Fonts::TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F}, text);

        SetForeColor(Color::dimGray, 1.0);
        Fonts::ChangeFontSize(BODY_SIZE);
        Fonts::SetFont(fonts.Body);
        Fonts::TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F - TITLE_SIZE}, "Press enter key to continue");

        GameManager::Render();

    }
    SceneManager::ChangeScene(SceneManager::Scenes::MainMenu);
}
