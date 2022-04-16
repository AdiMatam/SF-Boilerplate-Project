#include "SF-Core/Core.hpp"
#include "ScreenKeys.hpp"
#include "StartScreen.hpp"

#define SCREEN_GEN(className) [](){ return new className(); }

int main() {
    auto& renderer = WindowManager::Get();
    renderer.init();
    renderer.center();

    renderer.add(START_SCREEN, SCREEN_GEN(StartScreen));
    renderer.setScreen(START_SCREEN);

    renderer.run();
}