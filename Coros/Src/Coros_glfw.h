#pragma once

// The Header File of Coros dealing with glfw
#include "Coros.h"

namespace Coros
{
    bool Coros_glfw_Init(GLFWwindow* Window, bool EnableCorosCallbacks = true);
    bool Coros_glfw_ShutDown();
    
    // The Function which adds the Coros Callbacks with the user callbacks
    void Coros_glfw_EnableCallbacks();
    void Coros_glfw_ResetCallbacks();

    void Coros_glfw_KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
    void Coros_glfw_MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    void Coros_glfw_CursorPosCallback(GLFWwindow* window, double xpos, double ypos);
} // namespace Coros

