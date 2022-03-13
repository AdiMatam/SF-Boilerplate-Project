#pragma once

#include "Pch.hpp"
#include "WindowManager.hpp"

class BaseScreen {
private:
    BaseScreen() = default;
protected:
    WindowManager& renderer = WindowManager::Get();
public:
    virtual void onUpdate();
    virtual void onEvent(const sf::Event& ev);
    virtual void setupGeometry(); 
    virtual void setupWidgets(); 
};