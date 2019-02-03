#pragma once
#include <SFML\Graphics.hpp>
#include "Textbox.h"

class Snake;

class World
{
public:
	World(sf::Vector2u l_windSize, Snake& l_player);
	~World();

	static sf::Vector2u GetWindowSize();
	static int GetBlockSize();

	void RespawnApple(Snake& l_player);
	bool isPositionInSnake(int x, int y, Snake &l_player);

	void Update(Snake& l_player, Textbox& l_textbox);
	void Render(sf::RenderWindow& l_window);
private:
	static sf::Vector2u m_windowSize;
	sf::Vector2i m_applePosition;
	static int m_blockSize;

	sf::CircleShape m_appleShape;
	sf::RectangleShape m_bounds[4];
};