#include "SceneManager.h"

#include <iostream>

#include "Game.h"
#include "MainMenu.h"
#include "GameManager.h"
#include "AfterGame.h"


namespace SceneManager
{
    Scenes setScene = Scenes::MainMenu;
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
                Game::Play();
                std::cout << "Playing..." << std::endl;
                setScene = Scenes::MainMenu;
                break;
            case Scenes::Credits:
                //Credits();
                std::cout << "Credits..." << std::endl;
                setScene = Scenes::MainMenu;
                break;
            case Scenes::Rules:
                std::cout << "rules..." << std::endl;
                setScene = Scenes::MainMenu;
                break;
            case Scenes::Exit:
                //Exit();
                std::cout << "exit..." << std::endl;
                exit = true;
                break;
            case Scenes::AfterGame:
                PlayerWon::AfterScene(playerWon);
                break;
            case Scenes::Pause:
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
