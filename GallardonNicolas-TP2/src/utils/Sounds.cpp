#include "Sounds.h"

#include <sl.h>

namespace Sounds
{
    WAV LoadWAV(const std::string &filename)
    {
        return slLoadWAV(filename.c_str());
    }


    Sound SoundPlay(const WAV file)
    {
        return slSoundPlay(file);
    }


    Sound SoundLoop(const WAV file)
    {
        return slSoundLoop(file);
    }


    void SoundPause(const Sound sound)
    {
        slSoundPause(sound);
    }


    void SoundStop(const Sound sound)
    {
        slSoundStop(sound);
    }


    void SoundPauseAll()
    {
        slSoundPauseAll();
    }


    void SoundStopAll()
    {
        slSoundStopAll();
    }


    void SoundResumeAll()
    {
        slSoundResumeAll();
    }


    bool IsSoundPlaying(Sound sound)
    {
        return false;
    }


    bool IsSoundLooping(const Sound sound)
    {
        return slSoundLooping(sound);
    }
}