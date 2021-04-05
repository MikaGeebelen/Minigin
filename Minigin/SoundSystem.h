#pragma once
#include "SDL_mixer.h"
#include <list>
#include <mutex>
class BaseSoundSystem
{
public:
	virtual ~BaseSoundSystem();
	virtual void play(std::string soundPath, int volume) = 0;
protected:
	std::mutex m_Mutex{};
	bool m_IsThreadRunning = false;
};

class NullSoundSystem final: public BaseSoundSystem
{
public:
	virtual void play(std::string soundPath, int volume) override;
};

class SoundSystem final : public BaseSoundSystem
{
public:
	virtual void play(std::string soundPath, int volume) override;
private:
	std::list<Mix_Chunk*> m_SoundsToPlay{};
};

class LogSoundSystem final : public BaseSoundSystem
{
public:
	LogSoundSystem(BaseSoundSystem* pSoundSysten);
	virtual ~LogSoundSystem();
	virtual void play(std::string soundPath, int volume) override;
private:
	BaseSoundSystem* m_pSoundSystem = nullptr;
	std::list<std::string> m_SoundsToPlay{};
};