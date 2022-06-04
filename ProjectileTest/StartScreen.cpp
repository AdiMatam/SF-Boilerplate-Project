#include "StartScreen.hpp"

StartScreen::StartScreen() {
	std::cout << "Start Screen Loaded\n";
	setupGeometry();
	setupWidgets();

	m_StopAnim = false;
	m_AngleEchoer = NewRef<FrequentLaggyCall>(
		[this](bool* done) {
			Vec2f centerPos = getCorner(&m_Ball, m_Ball.getGlobalBounds(), Origin::Center);
			Vec2f mousePos = WindowManager::Get().getMousePosition();

			float angle = TO_DEG(
				atanf((centerPos.y - mousePos.y) / (mousePos.x - centerPos.x))
			);
			std::cout << angle << std::endl;
			*done = m_StopAnim;
		},
		sf::Time(sf::seconds(1.0f))
	);

}

void StartScreen::onEvent(const sf::Event& ev) {
	BaseScreen::onEvent(ev);
	if (keyPressed(ev, sf::Keyboard::Q))
		m_StopAnim = true;
}

void StartScreen::onUpdate() {
	sf::RenderWindow* window = WindowManager::Get().getWindow();
	window->clear(sf::Color::White);
	m_AngleEchoer->run();

	window->draw(m_Ground);
	window->draw(m_Ball);
	window->display();
}

void StartScreen::setupGeometry() {
	m_Ground.setSize(REL_VIEW(1.f, 0.25f));
	setOrigin(&m_Ground, m_Ground.getSize(), Origin::South | Origin::West);
	m_Ground.setPosition(REL_VIEW(0.f, 1.f));
	m_Ground.setFillColor(sf::Color::Green);

	m_Ball.setRadius(REL_VIEW_X(0.03f));
	setOrigin(&m_Ball, m_Ball.getGlobalBounds(), Origin::South | Origin::West);
	m_Ball.setPosition(getCorner(
		&m_Ground, m_Ground.getGlobalBounds(), Origin::North | Origin::West)
	);
	m_Ball.move(REL_VIEW(0.05f, 0.0f));
	m_Ball.setFillColor(sf::Color::Blue);
}


