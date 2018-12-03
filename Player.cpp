
//project includes
#include "Player.h"
#include "Framework/AssetManager.h"
#include "Level.h"

Player::Player()
	: GridObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandRight.png"));
}

void Player::Input(sf::Event _gameEvent)
{
	//Read the input from the keyboard and convert it to a direction
	// to move in (and then move)

	// Was the event a keypress?
	if (_gameEvent.type == sf::Event::KeyPressed)
	{
		//Yes it was a key press!

		//what key was pressed?
		if (_gameEvent.key.code == sf::Keyboard::W)
		{
			// it was W!
			//Move Up
			AttemptMove(sf::Vector2i(0, -1));
		}
		else if (_gameEvent.key.code == sf::Keyboard::A)
		{
			// it was A!
			//Move left
			AttemptMove(sf::Vector2i(-1, 0));
		}
		else if (_gameEvent.key.code == sf::Keyboard::S)
		{
			// it was S!
			//Move down
			AttemptMove(sf::Vector2i(0, 1));
		}
		else if (_gameEvent.key.code == sf::Keyboard::D)
		{
			// it was D!
			//Move right
			AttemptMove(sf::Vector2i(1, 0));
		}
	}
}

bool Player::AttemptMove(sf::Vector2i _direction)
{
	// Attempting to move in given direction

	//get current position
	//calculate target position
	sf::Vector2i targetPos = m_gridPosition + _direction;

	//check if the space is empty

	//if empty, move there
	return m_level->MoveObjectTo(this, targetPos);
}
