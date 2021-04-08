#pragma once
#include <iostream>
#include "ServiceLocater.h"
#include "SubjectComponent.h"
#include "Observer.h"

class TextureRenderComponent;
class Texture2D;

class Command
{
public:
	virtual ~Command() = default;
	virtual void Execute() = 0;
};

class CycleThroughMenu : public Command
{
public:
	CycleThroughMenu(TextureRenderComponent* menu,std::vector<std::shared_ptr<Texture2D>> menuPictures,bool cycleDir = true)
	:m_Pictures(menuPictures)
	,m_CyclesUp(cycleDir)
	, m_pMenu(menu)
	{}
	void Execute() override;

private:
	TextureRenderComponent* m_pMenu;
	size_t m_CurrentPicture = 0;
	std::vector<std::shared_ptr<Texture2D>> m_Pictures;
	bool m_CyclesUp;
};

class Die : public Command
{
public:
	Die(SubjectComponent* subject):m_pSubject(subject)
	{}
	void Execute() override { m_pSubject->Notify(Observer::Died); };
private:
	SubjectComponent* m_pSubject = nullptr;
};

class GainPoints : public Command
{
public:
	GainPoints(SubjectComponent* subject) :m_pSubject(subject)
	{}
	void Execute() override { m_pSubject->Notify(Observer::Coily); };
private:
	SubjectComponent* m_pSubject = nullptr;
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