#include "PCH/PCH.h"
#include "Coros.h"

#include "GLFW/glfw3.h"
#include "Coros_glfw.h"

// TODO: Events

void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    COROS_PRINT("[APP]: " << key)
}

int main(int, char **)
{
    int Result = glfwInit();

    if (Result != true)
        COROS_ERROR("GLFW Init Failed!!")

    // glfwWindowHint(GLFW_API ,GLFW_NO_API)

    GLFWwindow *Window = glfwCreateWindow(1200, 900, "Coros-UI", NULL, NULL);
    glfwMakeContextCurrent(Window);

    glfwSetKeyCallback(Window, KeyCallback);

    Coros::CreateCore();
    Coros::Init();

    Coros::Coros_glfw_Init(Window);

    auto IO = Coros::GetIO();
    auto Pos = IO.CursorPos;

    while (!glfwWindowShouldClose(Window))
    {
        IO = Coros::GetIO();

        glfwSwapBuffers(Window);

        Coros::BeginWindow("Window");
        Coros::EndWindow();

        Coros::BeginWindow("Window");
        Coros::EndWindow();

        Coros::BeginWindow("Window2");
        Coros::EndWindow();

        glfwPollEvents();
    }

    COROS_PRINT(Coros::GetWindowContextCount())
    Coros::ClearWindowContexts();

    Coros::Coros_glfw_ShutDown();
    Coros::ShutDown();
    glfwTerminate();

    return EXIT_SUCCESS;
}
