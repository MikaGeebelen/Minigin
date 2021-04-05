#pragma once
#include "Observer.h"
class TextRenderComponent;
class Lives : public Observer
{
public:
	Lives(TextRenderComponent* text, int lives);
	virtual void OnNotify(Events event) override;

private:
	TextRenderComponent* m_pText;
	int m_Lives;
};

