#include "application.hpp"

namespace game {
    application::application(const windowProperties& props) {
        display = std::make_unique<window>(props);
    }

    application::~application() {
    }

    void application::run() {
        while (display->isOpen()) {
            display->update();
        }
    }

}  // namespace game
