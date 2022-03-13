#include "Pch.hpp"
#include "BaseScreen.hpp"

void BaseScreen::onUpdate() {}
void BaseScreen::onEvent(const sf::Event& ev) {
    if (ev.type == sf::Event::Closed) {
        renderer.close();
    }
}
void BaseScreen::setupGeometry() {}
void BaseScreen::setupWidgets() {}