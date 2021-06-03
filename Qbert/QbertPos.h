#pragma once
#include <Observer.h>
class QbertPos : public Observer
{

public:
	void OnNotify(Event* event) override;
};
