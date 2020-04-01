#include "Character2.h"

Character2::Character2(AvailableBehaviours aStartBehaviour, int aStartPosition, std::string anIcon, Character* aTarget)
	:position(aStartPosition), icon(anIcon), currentBehaviour(new Behaviour()), target(aTarget)
{
	if (aTarget) {
		switch (aStartBehaviour)
		{
		case Character2::AvailableBehaviours::CHASE:
			currentBehaviour = new ChaseBehaviour();
			break;
		case Character2::AvailableBehaviours::EVADE:
			currentBehaviour = new EvadeBehaviour();
			break;
		default:
			break;
		}
		target = aTarget;
	}
}

Character2::~Character2()
{
}

void Character2::SetTarget(Character* aTarget)
{
	target = aTarget;
}

void Character2::Setbehaviour(AvailableBehaviours aBehaviour)
{

	switch (aBehaviour)
	{
	case Character2::AvailableBehaviours::IDLE:
		currentBehaviour = nullptr;
		break;
	case Character2::AvailableBehaviours::CHASE:
		currentBehaviour = new ChaseBehaviour();
		break;
	case Character2::AvailableBehaviours::EVADE:
		currentBehaviour = new EvadeBehaviour();
		break;
	default:
		break;
	}
}

int Character2::Update()
{
	if (target && currentBehaviour) {
		position = currentBehaviour->Update(position, target->GetPosition());
	}
	return position;
}

int Character2::GetPosition()
{
	return position;
}

std::string Character2::GetIcon()
{
	return icon;
}
