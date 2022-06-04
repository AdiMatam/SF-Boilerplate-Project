#include "StartScreen.hpp"

StartScreen::StartScreen() {
	std::cout << "Start Screen Loaded\n";
	setupGeometry();
	setupWidgets();
}

void StartScreen::onEvent(const sf::Event& ev) {
	BaseScreen::onEvent(ev);
}

void StartScreen::onUpdate() {
	sf::RenderWindow* window = WindowManager::Get().getWindow();
	window->clear();
	window->draw(m_Ground);
	window->display();
}

void StartScreen::setupGeometry() {
	m_Ground.setSize(REL_VIEW(1.f, 0.25f));
	setOrigin(&m_Ground, m_Ground.getSize(), Origin::South | Origin::West);
	m_Ground.setPosition(REL_VIEW(0.f, 1.f));
	m_Ground.setFillColor(sf::Color::Green);
}


