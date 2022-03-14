#include "Core/Core.hpp"

int main() {
    auto& renderer = WindowManager::Get();
    renderer.init();
    renderer.center();
    
    renderer.run();
}