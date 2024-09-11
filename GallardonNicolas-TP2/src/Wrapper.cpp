#include "Wrapper.h"
#include <random>

void Wrapper::InitWindow(int width, int height, std::string title, bool fullScreen)
{
	srand(time(nullptr));
}

void Wrapper::CloseWindow()
{
}

bool Wrapper::ShouldWindowClose()
{
	return false;
}

bool Wrapper::IsKeyDown(int key)
{
	return false;
}

bool Wrapper::IsKeyUp(int key)
{
	return false;
}

bool Wrapper::IsKeyPressing(int key)
{
	return false;
}

bool Wrapper::IsKeyReleasing(int key)
{
	return false;
}

Wrapper::Vector2 Wrapper::GetMousePos()
{
	return Vector2();
}

float Wrapper::GetDeltaTime()
{
	return 0.0f;
}

float Wrapper::TimeFromStart()
{
	return 0.0f;
}

void Wrapper::Render()
{
}

Wrapper::Texture Wrapper::LoadTexture(std::string filename)
{
	return Texture();
}

Wrapper::WAV Wrapper::LoadWAV(std::string filename)
{
	return WAV();
}

Wrapper::Sound Wrapper::SoundPlay(WAV file)
{
	return Sound();
}

Wrapper::Sound Wrapper::SoundLoop(WAV file)
{
	return Sound();
}

void Wrapper::SoundPause(Sound sound)
{
}

void Wrapper::SoundStop(Sound sound)
{
}

void Wrapper::SoundPauseAll()
{
}

void Wrapper::SoundStopAll()
{
}

void Wrapper::SoundResumeAll()
{
}

bool Wrapper::IsSoundPlaying(Sound sound)
{
	return false;
}

bool Wrapper::IsSoundLooping(Sound sound)
{
	return false;
}

void Wrapper::SetSpriteTiling(Vector2 position)
{
}

void Wrapper::SetSpriteScroll(Vector2 position)
{
}

void Wrapper::LoadSprite(int texture, Vector2 position, double width, double height)
{
}

Wrapper::Text Wrapper::LoadFont(std::string filename)
{
	return Text();
}

void Wrapper::SetFont(Text font)
{
}

void Wrapper::ChangeFontSize(int fontSize)
{
}

void Wrapper::TextPrint(Vector2 position, std::string text)
{
}

void Wrapper::SetBackColor(Color color)
{
}

void Wrapper::SetForeColor(Color color, float opacity)
{
}

void Wrapper::SetAdditiveBlend(bool enable)
{
}
