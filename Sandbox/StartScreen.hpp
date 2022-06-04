#pragma once

#include "SF-Core/Core.hpp"

class StartScreen : public BaseScreen {
private:
	sf::RectangleShape m_Ground;
	
public:
	StartScreen();
	void onEvent(const sf::Event& ev) override;
	void onUpdate() override;
	void setupGeometry();

};

