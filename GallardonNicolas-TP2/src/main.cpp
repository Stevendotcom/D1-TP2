#include "Wrapper.h"
#include "SceneManager.h"

using namespace Wrapper;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 900;

const std::string assetsDir = "../assets/";

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TEST", false);
    SceneManager::Manager();
}
