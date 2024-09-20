#pragma once
#include <string>

namespace GameManager
{

    void Start();
    void InitWindow(int width, int height, const std::string &title, bool fullScreen);
    void CloseWindow();
    bool ShouldWindowClose();
    void Render();
    int GetRandom(int min, int max);
    float GetFrameTime();
    float GetTime();
}
