﻿#include "Credits.h"

#include "Fonts.h"

using namespace Fonts;

void Credits::Credits()
{
    const int TITLE_SIZE = 60;
    const float MARGIN = 20.0f;
    const int BODY_SIZE = 15;

    ChangeFontSize(TITLE_SIZE);
    SetFont(fonts.Title);
    TextPrint({SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT - MARGIN}, "Thanks for playing!");

    ChangeFontSize(BODY_SIZE);
    SetFont(fonts.Body);
    TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F}, "Made by Nico Gallardo!");
    TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE}, "Banner by LukeThePolice");
    TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 2.0F}, "Antiquity Print by SciGho");
    TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 3.0F}, "Dirty Harold by GGBotNet");
    TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 4.0F},
              "Hana Caraka - Cozy Island Topdown Tileset by Bagong Games");
    TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 4.0F}, "Health & Stamina by Gowl");
    TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 5.0F}, "SimpleKeys by beamedeighth");
    TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 6.0F},
              "Some Sprites were edited using SpriteFusion");
    TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 7.0F},
              "Done on SIGIL engine by Geoff");
    TextPrint({SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0F - BODY_SIZE * 8.0F},
              "No little bunnies were harmed in the process of making this game.");

}
