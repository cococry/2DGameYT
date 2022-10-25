#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "core/application.hpp"

int main() {
    game::application* app = new game::application(game::windowProperties(1280, 720, "2D Game"));
    app->run();
    delete app;
}