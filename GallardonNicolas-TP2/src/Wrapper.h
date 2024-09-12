#pragma once
#include "sl.h"
#include <string>

namespace Wrapper
{
	struct Vector2
	{
		float X;
		float Y;
	};

	struct Color
	{
		float Red;
		float Green;
		float Blue;
	};

	enum class Key
	{
		KEY_ESCAPE,
		KEY_ENTER,
		KEY_TAB,
		KEY_BACKSPACE,
		KEY_INSERT,
		KEY_DELETE,
		KEY_RIGHT,
		KEY_LEFT,
		KEY_DOWN,
		KEY_UP,
		KEY_PAGE_UP,
		KEY_PAGE_DOWN,
		KEY_HOME,
		KEY_END,
		KEY_CAPS_LOCK,
		KEY_SCROLL_LOCK,
		KEY_NUM_LOCK,
		KEY_PRINT_SCREEN,
		KEY_PAUSE,
		KEY_F1,
		KEY_F2,
		KEY_F3,
		KEY_F4,
		KEY_F5,
		KEY_F6,
		KEY_F7,
		KEY_F8,
		KEY_F9,
		KEY_F10,
		KEY_F11,
		KEY_F12,
		KEY_F13,
		KEY_F14,
		KEY_F15,
		KEY_F16,
		KEY_F17,
		KEY_F18,
		KEY_F19,
		KEY_F20,
		KEY_KEYPAD_0,
		KEY_KEYPAD_1,
		KEY_KEYPAD_2,
		KEY_KEYPAD_3,
		KEY_KEYPAD_4,
		KEY_KEYPAD_5,
		KEY_KEYPAD_6,
		KEY_KEYPAD_7,
		KEY_KEYPAD_8,
		KEY_KEYPAD_9,
		KEY_KEYPAD_DECIMAL,
		KEY_KEYPAD_DIVIDE,
		KEY_KEYPAD_MULTIPLY,
		KEY_KEYPAD_SUBTRACT,
		KEY_KEYPAD_ADD,
		KEY_KEYPAD_ENTER,
		KEY_KEYPAD_EQUAL,
		KEY_LEFT_SHIFT,
		KEY_LEFT_CONTROL,
		KEY_LEFT_ALT,
		KEY_LEFT_SUPER,
		KEY_RIGHT_SHIFT,
		KEY_RIGHT_CONTROL,
		KEY_RIGHT_ALT,
		KEY_RIGHT_SUPER,
		MOUSE_BUTTON_1,
		MOUSE_BUTTON_2,
		MOUSE_BUTTON_3,
		MOUSE_BUTTON_4,
		MOUSE_BUTTON_5,
		MOUSE_BUTTON_6,
		MOUSE_BUTTON_7,
		MOUSE_BUTTON_LEFT,
		MOUSE_BUTTON_RIGHT,
		MOUSE_BUTTON_MIDDLE
	};

	typedef int Texture;
	typedef int WAV;
	typedef int Sound;
	typedef int Font;

    static int fontSize = 20;

	//Window

	void InitWindow(int width, int height, const std::string&title, bool fullScreen);
	void CloseWindow();
	bool ShouldWindowClose();
	
	//Input

	bool IsKeyDown(Key key);
	bool IsKeyUp(Key key);
	bool IsKeyPressing(Key key);
	bool IsKeyReleasing(Key key);
	Vector2 GetMousePos();

	//Rendering

	void Render();

	//Texture

	Texture LoadTexture(const std::string&filename);
	
	// Sound

	WAV LoadWAV(const std::string&filename);
	Sound SoundPlay(WAV file);
	Sound SoundLoop(WAV file);
	void SoundPause(Sound sound);
	void SoundStop(Sound sound);
	void SoundPauseAll();
	void SoundStopAll();
	void SoundResumeAll();
	bool IsSoundPlaying(Sound sound);
	bool IsSoundLooping(Sound sound);

	//Shape Drawing
	
	void SetSpriteTiling(Vector2 position);
	void SetSpriteScroll(Vector2 position);
	void LoadSprite(Texture texture, Vector2 position, float width, float height);
	
	//Text
	
	Font LoadFont(const std::string&filename);
	void SetFont(Font font);
	void ChangeFontSize(int size);
	void TextPrint(Vector2 position, const std::string&text);

	//Color
	void SetBackColor(const Color &color);
	void SetForeColor(const Color &color, float opacity);
	void SetAdditiveBlend(bool enable);
		
	//Utility
	int GetRandom(int min, int max);
}

