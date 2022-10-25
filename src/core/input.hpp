#pragma once

#include "defines.hpp"

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

namespace game {
    struct keyboardStruct {
        bool keysActive[GLFW_KEY_LAST];
        bool keysChanged[GLFW_KEY_LAST];
    };
    struct mouseStruct {
        bool buttonsActive[GLFW_MOUSE_BUTTON_LAST];
        bool buttonsChanged[GLFW_MOUSE_BUTTON_LAST];

        i32 ypos = 0, xpos = 0;
        i32 lastXpos = 0, lastYpos = 0;
        i32 xposDelta = 0, yposDelta = 0;
        i32 scrollDeltaX = 0, scrollDeltaY = 0;

        bool firstMouse = true;
    };
    class input {
       public:
        static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

        static void glfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

        static void glfwCursorPosCallback(GLFWwindow* window, double xpos, double ypos);

        static void glfwScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

        static bool keyIsPressed(u32 key);

        static bool keyWentDown(u32 key);

        static bool keyReleased(u32 key);

        static bool keyChanged(u32 key);

        static bool mouseButtonIsPressed(u32 button);

        static bool mouseButtonWentDown(u32 button);

        static bool mouseButtonReleased(u32 button);

        static bool mouseButtonChanged(u32 button);

        static glm::vec2 getCursorPos();

        static i32 getCursorX();

        static i32 getCursorY();

        static glm::vec2 getCursorPosDelta();

        static i32 getCursorXDelta();

        static i32 getCursorYDelta();

        static glm::vec2 getScrollDelta();

        static i32 getScrollDeltaX();

        static i32 getScrollDeltaY();

       private:
        static keyboardStruct mKeyboard;
        static mouseStruct mMouse;
    };
}  // namespace game
