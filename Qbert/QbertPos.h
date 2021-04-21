#pragma once
#include <Observer.h>
class QbertPos : public Observer
{

public:
	void OnNotify(Events event) override;
};
