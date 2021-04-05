#pragma once
#include "Obserever.h"
#include "TextRenderComponent.h"
class Score : public Obserever
{
public:
	Score(TextRenderComponent* text, int score);
	void OnNotify(Event event) override;

private:
	TextRenderComponent* m_pText;
	int m_Score;
};

