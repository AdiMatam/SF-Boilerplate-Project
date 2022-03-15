#include "Core/Core.hpp"
#include "ScreenKeys.hpp"

#define SCREEN_GEN(className) [](){ return className(); }

class StartScreen;

int main() {
    auto& renderer = WindowManager::Get();
    renderer.init();
    renderer.center();

    renderer.add(START_SCREEN, SCREEN_GEN(StartScreen));
    renderer.setScreen(START_SCREEN);

    renderer.run();
}