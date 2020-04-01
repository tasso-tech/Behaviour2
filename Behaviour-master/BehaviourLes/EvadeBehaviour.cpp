#include "EvadeBehaviour.h"

EvadeBehaviour::EvadeBehaviour()
{
}

EvadeBehaviour::~EvadeBehaviour()
{
}

int EvadeBehaviour::Update(int ownPosition, int targetPosition, int minPosition, int maxPosition)
{
	if (abs(ownPosition - targetPosition) < 10) {
		if (ownPosition < targetPosition && ownPosition > minPosition) {
			return ownPosition -1;
		}
		else if (ownPosition > targetPosition&& ownPosition < maxPosition) {
			return ownPosition +1;
		}
	}
	return ownPosition;
}

	

