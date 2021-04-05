#pragma once
#include "Obserever.h"
#include "TextRenderComponent.h"
class Lives : public Obserever
{
public:
	Lives(TextRenderComponent* text, int lives);
	void OnNotify(Event event) override;

private:
	TextRenderComponent* m_pText;
	int m_Lives;
};

