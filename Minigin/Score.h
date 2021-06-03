#pragma once
#include "Observer.h"
class TextRenderComponent;
class Score : public Observer
{
public:
	Score(TextRenderComponent* text, int score);
	virtual void OnNotify(Event* event) override;

private:
	TextRenderComponent* m_pText;
	int m_Score;
};

