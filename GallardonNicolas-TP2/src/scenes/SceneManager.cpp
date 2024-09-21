#include "SceneManager.h"

#include <iostream>

#include "Game.h"
#include "MainMenu.h"
#include "GameManager.h"
#include "AfterGame.h"
#include "Credits.h"
#include "Exit.h"
#include "Pause.h"
#include "Rules.h"


namespace SceneManager
{
    static Scenes setScene = Scenes::MainMenu;
    bool playerWon = false;

    void Manager()
    {
        bool exit = false;
        while (!GameManager::ShouldWindowClose() && !exit)
        {
            switch (setScene)
            {
            case Scenes::MainMenu:
                MainMenu::Menu();
                break;
            case Scenes::Play:
                playerWon = Game::Play();
                break;
            case Scenes::Pause:
                Pause::Pause();
                break;
            case Scenes::Credits:
                Credits::Credits();
                break;
            case Scenes::Rules:
                Rules::Rules();
                break;
            case Scenes::AfterGame:
                PlayerWon::AfterScene(playerWon);
                break;
            case Scenes::Exit:
                Exit::Exit();
                exit = true;
                break;
            default:
                std::cerr << "Unknown Scene #" << static_cast<int>(setScene) << std::endl;
                abort();
            }
        }
        GameManager::CloseWindow();
    }


    void ChangeScene(Scenes scene)
    {
        setScene = scene;
    }
}
