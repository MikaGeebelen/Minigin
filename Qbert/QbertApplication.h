#pragma once
#include <Minigin.h>
class QbertApplication : public Minigin
{
public:
	void UserInitialize() override;
	void UserLoadGame() const override;
	void UserCleanup() override;
};
