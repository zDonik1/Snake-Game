#include "Game.h"
#include <iostream>

Game::Game(int l_scrWidth, int l_scrHeight): m_window("Snake", sf::Vector2u(l_scrWidth, l_scrHeight)),
	m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(l_scrWidth, l_scrHeight), m_snake)
{
	RestartClock();
	m_textbox.Setup(5, 14, 350, sf::Vector2f((l_scrWidth - 350) / 2, 0));
	srand(time(NULL));
	m_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));
}

Game::~Game() {}

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed += m_clock.restart(); }
Window* Game::GetWindow() { return &m_window; }

void Game::HandleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetPhysicalDirection() != Direction::Down) {
		m_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetPhysicalDirection() != Direction::Up) {
		m_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetPhysicalDirection() != Direction::Right) {
		m_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetPhysicalDirection() != Direction::Left) {
		m_snake.SetDirection(Direction::Right);
	}
}

void Game::Update(){
	m_window.Update();

	float timestep = 1.0f / m_snake.GetSpeed();

	if (m_elapsed.asSeconds() >= timestep) {
		m_snake.Tick(m_textbox);
		m_world.Update(m_snake, m_textbox);
		m_elapsed -= sf::seconds(timestep);
		if (m_snake.HasLost()) {
			m_textbox.Add("Game over! Score: " + std::to_string(m_snake.GetScore()));
			m_snake.Reset();
		}
	}
}

void Game::Render() {
	m_window.BeginDraw(); // Clear.
	
	m_world.Render(*m_window.GetRenderWindow());
	m_snake.Render(*m_window.GetRenderWindow());
	m_textbox.Render(*m_window.GetRenderWindow());	

	m_window.EndDraw(); // Display.
}