#include "Pause.h"

#include <sl.h>

#include "Fonts.h"
#include "GameManager.h"
#include "Input.h"
#include "SceneManager.h"

using namespace Buttons;

enum class Selection
{
    Return,
    GoToMain,
    Exit
};

void Pause::Pause()
{
    int selected = 0;
    Button buttons[MAX_BUTTONS];

    MakeButtons(buttons);

    do
    {
        Buttons::Input(buttons, selected, MAX_BUTTONS);
        Draw(buttons);
    }
    while (!Input::IsKeyDown(SL_KEY_ENTER) && !GameManager::ShouldWindowClose());


    switch (static_cast<Selection>(selected))
    {
    case Selection::Return:
        //do nothing
        break;
    case Selection::GoToMain:
        ChangeScene(SceneManager::Scenes::MainMenu);
        break;
    case Selection::Exit:
        //todo cannot be set to this
        GameManager::CloseWindow();
        break;

    }


}

void Pause::MakeButtons(Button buttons[MAX_BUTTONS])
{
    const int width = 360;
    const int height = 100;

    for (int i = 0; i < MAX_BUTTONS; i++)
    {
        buttons[i] =
        {
            {SCREEN_WIDTH / 2.0F, height * static_cast<float>(MAX_BUTTONS - i) + 50.0F},
            {width, height},
            sprites.Button,
            Color::dimGray,
            Color::french,
        };
        switch (static_cast<Selection>(i + 1))
        {
        case Selection::Return:
            buttons[i].Selected = true;
            buttons[i].Text = "Return to Game";
            break;
        case Selection::GoToMain:
            buttons[i].Selected = false;
            buttons[i].Text = "Return to Main Menu";
            break;
        case Selection::Exit:
            buttons[i].Selected = false;
            buttons[i].Text = "Exit Game";
            break;
        }
    }

}



void Pause::Draw(Button buttons[MAX_BUTTONS])
{
    using namespace Fonts;
    ChangeFontSize(60);
    SetFont(fonts.Title);
    TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0F}, "Pause");

    SetFont(fonts.Body);
    ChangeFontSize(20);
    RenderButtons(buttons, MAX_BUTTONS);
    GameManager::Render();
}
