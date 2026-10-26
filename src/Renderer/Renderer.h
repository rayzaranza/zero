#pragma once
#include <glm/glm.hpp>


struct GLFWwindow;


namespace Zero {

class Renderer {
  public:
    static void Init(GLFWwindow* windowHandle);
    static void Clear(const glm::vec4& color = glm::vec4(0.01f, 0.01f, 0.01f, 1.0f));
    static void SetViewport(const glm::ivec2& position, const glm::uvec2& size);
};

}
