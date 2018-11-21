//Library Includes
#include <iostream>
#include <fstream>

// Project Includes
#include "Level.h"



Level::Level()
	: m_currentLevel(1)
{
	LoadLevel(1);
}

void Level::Draw(sf::RenderTarget& _target)
{
	sf::View camera = _target.getDefaultView();

	// Draw game world to the window
	_target.setView(camera);

	// Reset view
	_target.setView(_target.getDefaultView());


	// TODO
	//draw game objects

	

}


void Level::Update(sf::Time _frameTime)
{
	//TODO
}

void Level::LoadLevel(int _levelToLoad)
{
	// Clean up the old level

	//Delete any data already in the level
	//TODO
	

	//Clear out our lists
	//TODO
	

	// set the current level
	m_currentLevel = _levelToLoad;


	// Create new level

	// Open our file for reading
	std::ifstream inFile;
	std::string fileName = "levels/Level " + std::to_string(m_currentLevel) + ".txt";
	inFile.open(fileName);


	// Make sure the file was opened

	if (!inFile)
	{
		std::cerr << "Unable to open file " + fileName;
		exit(1);
	}

	// set the starting x and y coordinates used to position level objects
	float x = 0.0f;
	float y = 0.0f;

	// Define the spacing we will use for our grid

	const float X_SPACE = 105.0f;
	const float Y_SPACE = 105.0f;


	//Reading each character one by one from the file...
	char ch;

	// Each time, try to read the next character
	//if successfule execute the loop
	while (inFile >> std::noskipws >> ch)
	{
		// Perform actions based on what character was read

		if (ch == ' ')
		{
			x += X_SPACE;
		}
		else if (ch == '\n')
		{
			y += Y_SPACE;
			x = 0;
		}
		
		else
		{
			std::cerr << "Unregognised character in level file; " << ch;
		}
	}

	//close the file now that we are done with it
	inFile.close();
	


}

void Level::ReloadLevel()
{
	LoadLevel(m_currentLevel);
}

void Level::LoadNextLevel()
{
	LoadLevel(m_currentLevel + 1);
}