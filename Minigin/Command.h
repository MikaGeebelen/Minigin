#pragma once
#include <iostream>
#include "Subject.h"
#include "ServiceLocater.h"
class Command
{
public:
	virtual ~Command() = default;
	virtual void Execute() = 0;
};

class Die : public Command
{
public:
	Die(Subject* subject):m_pSubject(subject)
	{}
	void Execute() override { m_pSubject->Notify(Obserever::Event::died); };
private:
	Subject* m_pSubject = nullptr;
};

class GainPoints : public Command
{
public:
	GainPoints(Subject* subject) :m_pSubject(subject)
	{}
	void Execute() override { m_pSubject->Notify(Obserever::Event::coily); };
private:
	Subject* m_pSubject = nullptr;
};

class DiamondSound : public Command
{
public:
	void Execute() override { ServiceLocater::GetSoundSystem().play("../Data/Diamond.wav", 100); };
};

class OuchSound : public Command
{
public:
	void Execute() override { ServiceLocater::GetSoundSystem().play("../Data/Ouch.wav", 100); };
};

class SwitchToLogSoundSystem : public Command
{
public:
	void Execute() override { ServiceLocater::RegisterSoundSystem(new LogSoundSystem(new NullSoundSystem())); };
};

class SwitchToRegularSoundSystem : public Command
{
public:
	void Execute() override { ServiceLocater::RegisterSoundSystem(new SoundSystem()); };
};