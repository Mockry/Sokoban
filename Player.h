#pragma once

//Project includes
#include "GridObject.h"

class Player : public GridObject
{
public:
	Player();

	//ovverriding methods
	virtual void Input(sf::Event _gameEvent);

private:

	bool AttemptMove(sf::Vector2i _direction);



};