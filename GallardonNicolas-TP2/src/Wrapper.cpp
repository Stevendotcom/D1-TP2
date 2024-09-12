#include "Wrapper.h"

#include <iostream>
#include <random>

void Wrapper::InitWindow(const int width, const int height, const std::string&title, const bool fullScreen)
{
	srand(time(nullptr));
	slWindow(width, height, title.c_str(), fullScreen);
}

void Wrapper::CloseWindow()
{
	slClose();
}

bool Wrapper::ShouldWindowClose()
{
	return static_cast<bool>(slShouldClose());
}

bool Wrapper::IsKeyDown(Key key)
{
	return false;
}

bool Wrapper::IsKeyUp(Key key)
{
	return false;
}

bool Wrapper::IsKeyPressing(Key key)
{
	return false;
}

bool Wrapper::IsKeyReleasing(Key key)
{
	return false;
}

Wrapper::Vector2 Wrapper::GetMousePos()
{
	return {static_cast<float>(slGetMouseX()), static_cast<float>(slGetMouseY())};
}


void Wrapper::Render()
{
    slRender();
}

Wrapper::Texture Wrapper::LoadTexture(const std::string&filename)
{
	return slLoadTexture(filename.c_str());
}

Wrapper::WAV Wrapper::LoadWAV(const std::string&filename)
{
	return slLoadWAV(filename.c_str());
}

Wrapper::Sound Wrapper::SoundPlay(const WAV file)
{
	return slSoundPlay(file);
}

Wrapper::Sound Wrapper::SoundLoop(const WAV file)
{
	return slSoundLoop(file);
}

void Wrapper::SoundPause(const Sound sound)
{
    slSoundPause(sound);
}

void Wrapper::SoundStop(const Sound sound)
{
    slSoundStop(sound);
}

void Wrapper::SoundPauseAll()
{
    slSoundPauseAll();
}

void Wrapper::SoundStopAll()
{
    slSoundStopAll();
}

void Wrapper::SoundResumeAll()
{
    slSoundResumeAll();
}

bool Wrapper::IsSoundPlaying(Sound sound)
{
	return false;
}

bool Wrapper::IsSoundLooping(const Sound sound)
{
	return slSoundLooping(sound);
}

void Wrapper::SetSpriteTiling(const Vector2 position)
{
    slSetSpriteTiling(static_cast<float>(position.X), static_cast<float>(position.Y));
}

void Wrapper::SetSpriteScroll(Vector2 position)
{
    if (position.X > FLT_EPSILON + 1.0f && position.X < 0 && position.Y < 0 && position.Y > FLT_EPSILON + 1.0f)
    {
        std::cout << "Scroll higher than the permited amount";
        abort();
    }
    slSetSpriteScroll(position.X, position.Y);
}

void Wrapper::LoadSprite(const Texture texture, const Vector2 position, const float width, const float height)
{
    slSprite(texture, position.X, position.Y, width, height);
}

Wrapper::Font Wrapper::LoadFont(const std::string&filename)
{
	return slLoadFont(filename.c_str());
}

void Wrapper::SetFont(Font font)
{
    slSetFont(font, fontSize);
}

void Wrapper::ChangeFontSize(int size)
{
    fontSize = size;
    slSetFontSize(fontSize);
}

void Wrapper::TextPrint(const Vector2 position, const std::string& text)
{
    slText(position.X, position.Y, text.c_str());
}

void Wrapper::SetBackColor(const Color &color)
{
    slSetBackColor(color.Red, color.Green, color.Blue);
}

void Wrapper::SetForeColor(const Color &color, const float opacity)
{
    slSetForeColor(color.Red, color.Green, color.Blue, opacity);
}

void Wrapper::SetAdditiveBlend(const bool enable)
{
    slSetAdditiveBlend(enable);
}

int Wrapper::GetRandom(const int min, const int max)
{
	return rand() % (max + 1 - min) + min;
}
