#pragma once
#include "../Core/Types.h"

#include <memory>
#include <string>
#include <glm/glm.hpp>
#include <functional>
#include "../Event/Event.h"

struct GLFWwindow;


namespace Zero {


struct WindowProps {
    std::string Title { "" };
    glm::uvec2 Size { 1920u, 1080u };
    std::function<void(Event&)> EventCallback;
};


class Window {
  public:
    Window(const WindowProps& props);
    ~Window();

  public:
    static Scope<Window> Create(const WindowProps& props)
    {
        return CreateScope<Window>(props);
    }

  public:
    void Update() const;
    void Resize(const glm::uvec2& size);
    void SetEventCallback(std::function<void(Event&)> callback);

  private:
    static WindowProps& GetWindowProps(GLFWwindow* window);

  private:
    GLFWwindow* m_WindowHandle;
    WindowProps m_Props;
};


}
