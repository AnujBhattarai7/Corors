#include "PCH.h"
#include "GLFW/glfw3.h"
#include "Coros_glfw.h"

namespace Coros
{
    struct Coros_glfw_impl
    {
        // Stores the callback if implemented by user else nullptr
        GLFWkeyfun UserKeyCallback = nullptr;
        GLFWmousebuttonfun UserMouseButtonCallback = nullptr;
        GLFWcursorposfun UserCursorCallback = nullptr;

        GLFWwindow *Window;
        bool EnableCallbacks = false;

        Coros_glfw_impl() {}
    };

    CorosKeys GetCorosKeyFromGlfw(int key)
    {
        switch (key)
        {
        case GLFW_KEY_A:
            return CorosKey_A;
        case GLFW_KEY_B:
            return CorosKey_B;
        case GLFW_KEY_C:
            return CorosKey_C;
        case GLFW_KEY_D:
            return CorosKey_D;
        case GLFW_KEY_E:
            return CorosKey_E;
        case GLFW_KEY_F:
            return CorosKey_F;
        case GLFW_KEY_G:
            return CorosKey_G;
        case GLFW_KEY_H:
            return CorosKey_H;
        case GLFW_KEY_I:
            return CorosKey_I;
        case GLFW_KEY_J:
            return CorosKey_J;
        case GLFW_KEY_K:
            return CorosKey_K;
        case GLFW_KEY_L:
            return CorosKey_L;
        case GLFW_KEY_M:
            return CorosKey_M;
        case GLFW_KEY_N:
            return CorosKey_N;
        case GLFW_KEY_O:
            return CorosKey_O;
        case GLFW_KEY_P:
            return CorosKey_P;
        case GLFW_KEY_Q:
            return CorosKey_Q;
        case GLFW_KEY_R:
            return CorosKey_R;
        case GLFW_KEY_S:
            return CorosKey_S;
        case GLFW_KEY_T:
            return CorosKey_T;
        case GLFW_KEY_U:
            return CorosKey_U;
        case GLFW_KEY_W:
            return CorosKey_W;
        case GLFW_KEY_V:
            return CorosKey_V;
        case GLFW_KEY_X:
            return CorosKey_X;
        case GLFW_KEY_Y:
            return CorosKey_Y;
        case GLFW_KEY_Z:
            return CorosKey_Z;

        case GLFW_KEY_KP_0:
            return CorosKey_Np_0;
        case GLFW_KEY_KP_1:
            return CorosKey_Np_1;
        case GLFW_KEY_KP_2:
            return CorosKey_Np_2;
        case GLFW_KEY_KP_3:
            return CorosKey_Np_3;
        case GLFW_KEY_KP_4:
            return CorosKey_Np_4;
        case GLFW_KEY_KP_5:
            return CorosKey_Np_5;
        case GLFW_KEY_KP_6:
            return CorosKey_Np_6;
        case GLFW_KEY_KP_7:
            return CorosKey_Np_7;
        case GLFW_KEY_KP_8:
            return CorosKey_Np_8;
        case GLFW_KEY_KP_9:
            return CorosKey_Np_9;

        case GLFW_KEY_0:
            return CorosKey_0;
        case GLFW_KEY_1:
            return CorosKey_1;
        case GLFW_KEY_2:
            return CorosKey_2;
        case GLFW_KEY_3:
            return CorosKey_3;
        case GLFW_KEY_4:
            return CorosKey_4;
        case GLFW_KEY_5:
            return CorosKey_5;
        case GLFW_KEY_6:
            return CorosKey_6;
        case GLFW_KEY_7:
            return CorosKey_7;
        case GLFW_KEY_8:
            return CorosKey_8;
        case GLFW_KEY_9:
            return CorosKey_9;

        case GLFW_MOUSE_BUTTON_RIGHT:
            return CorosKey_MouseButtonRight;
        case GLFW_MOUSE_BUTTON_MIDDLE:
            return CorosKey_MouseButtonMiddle;
        case GLFW_MOUSE_BUTTON_LEFT:
            return CorosKey_MouseButtonLeft;

        case GLFW_KEY_ENTER:
            return CorosKey_Enter;
        case GLFW_KEY_NUM_LOCK:
            return CorosKey_NumLock;
        case GLFW_KEY_CAPS_LOCK:
            return CorosKey_CapsLock;
        case GLFW_KEY_ESCAPE:
            return CorosKey_Escape;
        case GLFW_KEY_COMMA:
            return CorosKey_Comma;

        case GLFW_KEY_LEFT_SHIFT:
            return CorosKey_LeftShift;
        case GLFW_KEY_LEFT_CONTROL:
            return CorosKey_LeftCtrl;
        case GLFW_KEY_LEFT_SUPER:
            return CorosKey_LeftSuper;
        case GLFW_KEY_LEFT_ALT:
            return CorosKey_LeftAlt;
        case GLFW_KEY_LEFT_BRACKET:
            return CorosKey_LeftBracket;

        case GLFW_KEY_RIGHT_SHIFT:
            return CorosKey_RightShift;
        case GLFW_KEY_RIGHT_CONTROL:
            return CorosKey_RightCtrl;
        case GLFW_KEY_RIGHT_SUPER:
            return CorosKey_RightSuper;
        case GLFW_KEY_RIGHT_ALT:
            return CorosKey_RightAlt;
        case GLFW_KEY_RIGHT_BRACKET:
            return CorosKey_RightBracket;
        default:
            return CorosKey_None;
        }
    }

    CorosKeys GetCorosModFromGlfw(int mod)
    {
        switch (mod)
        {
        case GLFW_MOD_SHIFT:
            return CorosKey_ModShift;
        case GLFW_MOD_ALT:
            return CorosKey_ModAlt;
        case GLFW_MOD_CAPS_LOCK:
            return CorosKey_ModCapsLock;
        case GLFW_MOD_CONTROL:
            return CorosKey_ModCtrl;
        case GLFW_MOD_SUPER:
            return CorosKey_ModSuper;
        case GLFW_MOD_NUM_LOCK:
            return CorosKey_ModNumLock;
        default:
            return CorosKey_None;
        }
    }

    Coros_glfw_impl *GetCorosGlfwImpl()
    {
        return ((Coros_glfw_impl *)GetIO().WindowPlatformPointer == nullptr) ? nullptr : (Coros_glfw_impl *)GetIO().WindowPlatformPointer;
    }

    bool Coros_glfw_Init(GLFWwindow *Window, bool EnableCorosCallbacks)
    {
        Coros_glfw_impl *Impl = new Coros_glfw_impl();
        Impl->Window = Window;

        Impl->EnableCallbacks = EnableCorosCallbacks;

        IO &io = GetIO();
        io.WindowPlatformPointer = (void *)Impl;

        if (EnableCorosCallbacks)
            Coros_glfw_EnableCallbacks();

        return true;
    }

    bool Coros_glfw_ShutDown()
    {
        Coros_glfw_impl *Impl = GetCorosGlfwImpl();
        if (Impl == nullptr)
            return false;

        if (Impl->EnableCallbacks)
            Coros_glfw_ResetCallbacks();

        delete Impl;

        GetIO().WindowPlatformPointer = nullptr;
        GetIO().WindowPlatformType = WindowPlatforms::None;

        return true;
    }

    void Coros_glfw_EnableCallbacks()
    {
        Coros_glfw_impl *Impl = GetCorosGlfwImpl();

        Impl->UserKeyCallback = glfwSetKeyCallback(Impl->Window, Coros_glfw_KeyCallBack);
        Impl->UserMouseButtonCallback = glfwSetMouseButtonCallback(Impl->Window, Coros_glfw_MouseButtonCallback);
        Impl->UserCursorCallback = glfwSetCursorPosCallback(Impl->Window, Coros_glfw_CursorPosCallback);

        Impl->EnableCallbacks = true;
    }

    void Coros_glfw_ResetCallbacks()
    {
        Coros_glfw_impl *Impl = GetCorosGlfwImpl();

        glfwSetKeyCallback(Impl->Window, Impl->UserKeyCallback);
        Impl->UserKeyCallback = nullptr;

        glfwSetMouseButtonCallback(Impl->Window, Impl->UserMouseButtonCallback);
        Impl->UserMouseButtonCallback = nullptr;

        glfwSetCursorPosCallback(Impl->Window, Impl->UserCursorCallback);
        Impl->UserCursorCallback = nullptr;

        Impl->EnableCallbacks = false;
    }

    void Coros_glfw_KeyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        Coros_glfw_impl *Impl = GetCorosGlfwImpl();
        IO &io = GetIO();

        if (Impl->EnableCallbacks && Impl->UserKeyCallback != nullptr)
            Impl->UserKeyCallback(window, key, scancode, action, mods);

        io.AddKeyEvent(GetCorosKeyFromGlfw(key), (action == GLFW_PRESS));

        if (mods > 0)
        {
            COROS_PRINT(mods)
        }
    }

    void Coros_glfw_MouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
    {
        Coros_glfw_impl *Impl = GetCorosGlfwImpl();
        IO &io = GetIO();

        if (Impl->EnableCallbacks && Impl->UserMouseButtonCallback != nullptr)
            Impl->UserMouseButtonCallback(window, button, action, mods);

        io.AddMouseButtonEvent(GetCorosKeyFromGlfw(button), (action == GLFW_PRESS));
    }

    void Coros_glfw_CursorPosCallback(GLFWwindow *window, double xpos, double ypos)
    {
        Coros_glfw_impl *Impl = GetCorosGlfwImpl();
        IO &io = GetIO();

        if (Impl->EnableCallbacks && Impl->UserCursorCallback != nullptr)
            Impl->UserCursorCallback(window, xpos, ypos);

        io.AddCursorPosEvent({xpos, ypos});
    }

} // namespace Coros
