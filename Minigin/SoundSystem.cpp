#include "MiniginPCH.h"
#include "SoundSystem.h"
#include <thread>

BaseSoundSystem::~BaseSoundSystem()
{
	m_IsThreadRunning = false;
	while (!m_Mutex.try_lock())
	{
	}
	m_Mutex.unlock();
}

void NullSoundSystem::play(std::string , int )
{}

void SoundSystem::play(std::string soundPath, int volume)
{
	if (!m_IsThreadRunning)
	{
		m_IsThreadRunning = true;
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
		if (m_CreatedSounds[soundPath] == nullptr)
		{
			m_CreatedSounds[soundPath] = Mix_LoadWAV(soundPath.c_str());
		}
		m_CreatedSounds[soundPath]->volume = (Uint8)volume;
		m_SoundsToPlay.push_back(m_CreatedSounds[soundPath]);
		
		std::thread audioThread{ [this]()
		{
			while (m_IsThreadRunning)
			{
				std::lock_guard<std::mutex> lock{ m_Mutex };
				if (!m_SoundsToPlay.empty())
				{
					Mix_Chunk* pCurrentSound = m_SoundsToPlay.front();
					m_SoundsToPlay.pop_front();
					Mix_PlayChannel(-1, pCurrentSound, 0);
				}
			}
		}};
		if (audioThread.joinable())
		{
			audioThread.detach();
		}
	}
	else
	{
		std::lock_guard<std::mutex> lock{ m_Mutex };
		if (m_CreatedSounds[soundPath] == nullptr)
		{
			m_CreatedSounds[soundPath] = Mix_LoadWAV(soundPath.c_str());
		}
		m_CreatedSounds[soundPath]->volume = (Uint8)volume;
		m_SoundsToPlay.push_back(m_CreatedSounds[soundPath]);
	}
}

LogSoundSystem::LogSoundSystem(BaseSoundSystem* pSoundSysten)
	:m_pSoundSystem(pSoundSysten)
{
}

LogSoundSystem::~LogSoundSystem()
{
	delete m_pSoundSystem;
	m_pSoundSystem = nullptr;
}

void LogSoundSystem::play(std::string soundPath, int volume)
{
	std::cout << "Path to sound is: " << soundPath << " volume is: " << std::to_string(volume) << '\n';
	m_pSoundSystem->play(soundPath, volume);
}
