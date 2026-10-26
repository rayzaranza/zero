#include "Renderer.h"
#include "../Logger/Logger.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void Zero::Renderer::Init(GLFWwindow* windowHandle)
{
    glfwMakeContextCurrent(windowHandle);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        Z_LOG_CRITICAL("Failed to load OpenGL");
        return;
    }
}


void Zero::Renderer::Clear(const glm::vec4& color)
{
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}


void Zero::Renderer::SetViewport(const glm::ivec2& position, const glm::uvec2& size)
{
    glViewport(position.x, position.y, size.x, size.y);
}
