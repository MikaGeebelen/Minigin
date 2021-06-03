#pragma once
#include "Observer.h"
class Event;
class TextRenderComponent;
class Lives : public Observer
{
public:
	Lives(TextRenderComponent* text, int lives);
	virtual void OnNotify(Event* event) override;

private:
	TextRenderComponent* m_pText;
	int m_Lives;
};

