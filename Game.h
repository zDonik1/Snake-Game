#pragma once
#include "Window.h"
#include "World.h"
#include "Snake.h"
#include "Textbox.h"
#include <SFML\Window.hpp>

class Game{
public:
	Game(int l_scrWidth, int l_scrHeight);
	~Game();

	void HandleInput();
	void Update();
	void Render();

	Window* GetWindow();

	sf::Time GetElapsed();
	void RestartClock();
private:
	Window m_window;
	sf::Clock m_clock;
	sf::Time m_elapsed;
	Textbox m_textbox;

	World m_world;
	Snake m_snake;
};