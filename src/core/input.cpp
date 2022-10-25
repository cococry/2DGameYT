#include "input.hpp"

namespace game {

    keyboardStruct input::mKeyboard;
    mouseStruct input::mMouse;

    void input::glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (action != GLFW_RELEASE) {
            if (!mKeyboard.keysActive[key]) {
                mKeyboard.keysActive[key] = true;
            }
        } else {
            mKeyboard.keysActive[key] = false;
        }
        mKeyboard.keysChanged[key] = (action != GLFW_REPEAT);
    }
    void input::glfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        if (action != GLFW_RELEASE) {
            if (!mMouse.buttonsActive[button]) {
                mMouse.buttonsActive[button] = true;
            }
        } else {
            mMouse.buttonsActive[button] = false;
        }
        mMouse.buttonsChanged[button] = (action != GLFW_REPEAT);
    }
    void input::glfwCursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
        mMouse.xpos = xpos;
        mMouse.ypos = ypos;

        if (mMouse.firstMouse) {
            mMouse.lastXpos = xpos;
            mMouse.lastYpos = ypos;
            mMouse.firstMouse = false;
        }

        mMouse.xposDelta = mMouse.xpos - mMouse.lastXpos;
        mMouse.yposDelta = mMouse.ypos - mMouse.lastYpos;
        mMouse.lastXpos = xpos;
        mMouse.lastYpos = ypos;
    }
    void input::glfwScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
        mMouse.scrollDeltaX = xoffset;
        mMouse.scrollDeltaY = yoffset;
    }
    bool input::keyIsPressed(u32 key) {
        return mKeyboard.keysActive[key];
    }
    bool input::keyWentDown(u32 key) {
        return keyChanged(key) && mKeyboard.keysActive[key];
    }
    bool input::keyReleased(u32 key) {
        return keyChanged(key) && !mKeyboard.keysActive[key];
    }
    bool input::keyChanged(u32 key) {
        bool ret = mKeyboard.keysChanged[key];
        mKeyboard.keysChanged[key] = false;
        return ret;
    }
    bool input::mouseButtonIsPressed(u32 button) {
        return mMouse.buttonsActive[button];
    }
    bool input::mouseButtonWentDown(u32 button) {
        return mouseButtonChanged(button) && mMouse.buttonsActive[button];
    }
    bool input::mouseButtonReleased(u32 button) {
        return mouseButtonChanged(button) && !mMouse.buttonsActive[button];
    }
    bool input::mouseButtonChanged(u32 button) {
        bool ret = mMouse.buttonsChanged[button];
        mMouse.buttonsChanged[button] = false;
        return ret;
    }
    glm::vec2 input::getCursorPos() {
        return glm::vec2(mMouse.xpos, mMouse.ypos);
    }
    i32 input::getCursorX() {
        return mMouse.xpos;
    }
    i32 input::getCursorY() {
        return mMouse.ypos;
    }
    glm::vec2 input::getCursorPosDelta() {
        return glm::vec2(mMouse.xposDelta, mMouse.yposDelta);
    }
    i32 input::getCursorXDelta() {
        return mMouse.xposDelta;
    }
    i32 input::getCursorYDelta() {
        return mMouse.yposDelta;
    }
    glm::vec2 input::getScrollDelta() {
        return glm::vec2(mMouse.scrollDeltaX, mMouse.scrollDeltaY);
    }
    i32 input::getScrollDeltaX() {
        return mMouse.scrollDeltaX;
    }
    i32 input::getScrollDeltaY() {
        return mMouse.scrollDeltaY;
    }
}  // namespace game
