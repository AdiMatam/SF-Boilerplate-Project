#pragma once

#include "SF-Core/Core.hpp"

class StartScreen : public BaseScreen {
private:
	sf::RectangleShape m_Ground;
	sf::CircleShape m_Ball;

	// temp
	Ref<FrequentLaggyCall> m_AngleEchoer;
	bool m_StopAnim;
	//
	
public:
	StartScreen();
	void onEvent(const sf::Event& ev) override;
	void onUpdate() override;
	void setupGeometry();

};

