#include "Window.h"
#include "../Logger/Logger.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <utility>
#include "../Event/AppEvent.h"


Zero::Window::Window(const WindowProps& props) : m_Props { props }
{
    glfwSetErrorCallback([](int error, const char* description) {
        Z_LOG_ERROR("[GLFW Error: {0}] {1}\n", error, description);
    });

    if (!glfwInit()) {
        Z_LOG_CRITICAL("Error initializing GLFW");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
    glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);

    m_WindowHandle = glfwCreateWindow(props.Size.x, props.Size.y, props.Title.c_str(), nullptr, nullptr);

    if (!m_WindowHandle) {
        Z_LOG_CRITICAL("Error creating GLFW Window");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_WindowHandle);

    // TODO: move to Renderer
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

    glfwSetWindowUserPointer(m_WindowHandle, &m_Props);

    glfwSetWindowCloseCallback(m_WindowHandle, [](GLFWwindow* window) {
        WindowProps& props { GetWindowProps(window) };
        WindowClosedEvent event {};
        props.EventCallback(event);
    });

    glfwSetWindowSizeCallback(m_WindowHandle, [](GLFWwindow* window, int width, int height) {
        WindowProps& props { GetWindowProps(window) };
        WindowResizedEvent event { glm::uvec2 { width, height } };
        props.EventCallback(event);
    });

    Z_LOG("Window created");
}


Zero::Window::~Window()
{
    glfwDestroyWindow(m_WindowHandle);
    glfwTerminate();

    Z_LOG("Window destroyed");
}


void Zero::Window::Update() const
{
    // TODO: move to Renderer
    glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwPollEvents();
    glfwSwapBuffers(m_WindowHandle);
}


void Zero::Window::Resize(const glm::uvec2& size)
{
    m_Props.Size = size;
    glViewport(0, 0, size.x, size.y);
}


void Zero::Window::SetEventCallback(std::function<void(Event&)> callback)
{
    m_Props.EventCallback = callback;
}


Zero::WindowProps& Zero::Window::GetWindowProps(GLFWwindow* window)
{
    return *(WindowProps*)glfwGetWindowUserPointer(window);
}
