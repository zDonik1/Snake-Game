#pragma once
#include <SFML\Graphics.hpp>
#include "Textbox.h"
#include "World.h"

struct SnakeSegment
{
	sf::Vector2i position;
	SnakeSegment(int x, int y) : position(x, y) {}
};

using SnakeContainer = std::vector<SnakeSegment>;

enum Direction{ None, Up, Down, Left, Right };

class Snake
{
public:
	Snake(int l_blockSize);
	~Snake();

	//Helper methods
	void SetDirection(Direction l_dir);
	Direction GetDirection();
	int GetSpeed();
	sf::Vector2i GetPosition();
	int GetLives();
	int GetScore();
	void IncreaseScore();
	bool HasLost();
	Direction GetPhysicalDirection();

	void Lose();
	void ToggleLost();

	void Extend();
	void Reset();

	void Move();
	void Tick(Textbox& l_textbox);
	void Cut(int l_segments);
	void Render(sf::RenderWindow &l_window);

	SnakeContainer m_snakeBody;

private:
	void CheckCollision(Textbox& l_textbox);

	int m_size;
	Direction m_dir;
	int m_speed;
	int m_lives;
	int m_score;
	bool m_lost;
	sf::RectangleShape m_bodyRect;
};