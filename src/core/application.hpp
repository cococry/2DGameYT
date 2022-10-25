#pragma once

#include "window.hpp"

#include <memory>

namespace game {
    class application {
       public:
        application(const windowProperties& props);

        ~application();

        void run();

        std::unique_ptr<window> display;

       private:
    };
}  // namespace game
