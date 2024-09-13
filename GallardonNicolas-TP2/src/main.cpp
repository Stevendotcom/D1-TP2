#include "Wrapper.h"
#include "scenes/SceneManager.h"

using namespace Wrapper;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 900;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TEST", false);
    const std::string assetsDir = "../assets/";

    const Font font = LoadFont(assetsDir + "DirtyHarold_Font/DirtyHarold.ttf");
    SetFont(font);

    SceneManager::Manager();
}
