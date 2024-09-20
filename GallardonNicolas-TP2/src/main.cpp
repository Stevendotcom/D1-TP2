#include <string>

#include "Fonts.h"
#include "GameManager.h"
#include "Sprites.h"


const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;
const std::string ASSETS_DIR = "assets/";
const std::string GAME_TITLE = "Good Name";
Fonts::Fonts fonts;
Sprites::Sprites sprites;

int main()
{
    GameManager::Start();
}
