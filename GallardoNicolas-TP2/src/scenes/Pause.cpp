#include "Pause.h"

#include <sl.h>

#include "Background.h"
#include "Fonts.h"
#include "GameManager.h"
#include "Input.h"
#include "SceneManager.h"

using namespace Buttons;


void Pause::Pause(bool &returnMain)
{
    int selected = 0;
    Button buttons[MAX_BUTTONS];

    MakeButtons(buttons);

    do
    {
        Buttons::Input(buttons, selected, MAX_BUTTONS);
        Draw(buttons);
    }
    while (!Input::IsKeyReleasing(SL_KEY_ENTER) && !GameManager::ShouldWindowClose());


    if (static_cast<Selection>(selected) == Selection::GoToMain)
    {
        returnMain = true;
        ChangeScene(SceneManager::Scenes::MainMenu);
    }


}

void Pause::MakeButtons(Button buttons[MAX_BUTTONS])
{
    constexpr int width = 360;
    constexpr int height = 100;

    for (int i = 0; i < MAX_BUTTONS; i++)
    {
        buttons[i] =
        {
            {SCREEN_WIDTH / 2.0F, height * static_cast<float>(MAX_BUTTONS - i) + 50.0F},
            {width, height},
            sprites.Button,
            Color::DIM_GRAY,
            Color::FRENCH,
        };
        switch (static_cast<Selection>(i))
        {
        case Selection::GoToMain:
            buttons[i].Selected = true;
            buttons[i].Text = "Return to Main Menu";
            break;
        case Selection::Return:
            buttons[i].Selected = false;
            buttons[i].Text = "Return to Game";
            break;
        }
    }

}


void Pause::Draw(Button buttons[MAX_BUTTONS])
{
    using namespace Fonts;

    Background::Draw();

    ChangeFontSize(60);
    SetForeColor(Color::COFFEE, 1.0);
    SetFont(fonts.Title);
    TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F}, "Pause");

    SetFont(fonts.Body);
    ChangeFontSize(20);
    RenderButtons(buttons, MAX_BUTTONS);
    GameManager::Render();
}
