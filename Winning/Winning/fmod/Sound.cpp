#pragma once
#include"Sound.h"

Sound::Sound()
{
	FMOD::System_Create(&system);
	musicVolume = 1.0f;
	sfxVolume = 1.0f;
	system->init(100, FMOD_INIT_NORMAL, 0);
}

FMOD::Sound* Sound::CreateSound(char *title,bool stream)
{
	FMOD::Sound *data;
	if(stream == true)
		system->createStream(title, FMOD_DEFAULT, 0, &data);
	else
		system->createSound(title,FMOD_DEFAULT,0, &data);
	return data;
}

void Sound::PlayMusic(FMOD::Sound *sound,float volume)
{
	system->playSound(FMOD_CHANNEL_FREE, sound, true, &musicChannel);

	musicChannel->setVolume(volume);		// Set the volume while it is paused.
	
	musicChannel->setPaused(false);		// This is where the sound really starts.
	

}

void Sound::PauseMusic(bool pause)
{
	musicChannel->setPaused(pause);
}

void Sound::ChangeVolumeMusic(float volume)
{
	musicChannel->setVolume(volume);
	musicVolume = volume;
}

void Sound::PlaySFX(FMOD::Sound *sound,float volume)
{
	system->playSound(FMOD_CHANNEL_FREE, sound, true, &sfxChannel);

	sfxChannel->setVolume(volume);		// Set the volume while it is paused.
	
	sfxChannel->setPaused(false);		// This is where the sound really starts.
	

}

void Sound::PauseSFX(bool pause)
{
	sfxChannel->setPaused(pause);
}

void Sound::ChangeVolumeSFX(float volume)
{
	sfxChannel->setVolume(volume);
	sfxVolume = volume;
}

Sound::~Sound()
{
	system->release();
}