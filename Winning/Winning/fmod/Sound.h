#pragma once
#include"fmod.hpp"
#include"fmod_errors.h"
#include"fmod_codec.h"
#include"fmod_dsp.h"
#include"fmod_memoryinfo.h"
#include"fmod_output.h"


class Sound
{
public:
	Sound();
	~Sound();
	FMOD::Sound* Sound::CreateSound(char *title,bool stream);
	void PlayMusic(FMOD::Sound *sound,float volume);
	void PauseMusic(bool pause);
	void ChangeVolumeMusic(float volume);

	void PlaySFX(FMOD::Sound *sound,float volume);
	void PauseSFX(bool pause);
	void ChangeVolumeSFX(float volume);

	FMOD::System *system;
	FMOD::Channel *musicChannel;
	FMOD::Channel *sfxChannel;

	float musicVolume;
	float sfxVolume;
};
