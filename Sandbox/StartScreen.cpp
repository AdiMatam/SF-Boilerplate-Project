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
	window->draw(m_Cover);
	window->display();
}

void StartScreen::setupGeometry() {
	m_Cover.setSize(REL_VIEW(0.75f, 0.75f));
	m_Cover.setFillColor(sf::Color::Green);

}


