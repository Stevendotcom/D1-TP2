#pragma once

namespace SceneManager
{

    enum class Scenes
    {
        MainMenu,
        Play,
        Credits,
        Rules,
        Exit,
        AfterGame,
        Pause,
    };

    void Manager();
    void ChangeScene(Scenes scene);
}
