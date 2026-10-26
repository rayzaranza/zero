#pragma once
#include <memory>
#include "../Window/Window.h"
#include "../Core/Types.h"
#include "../Event/Event.h"
#include "../Logger/Logger.h"
#include "../Event/AppEvent.h"
#include "../Core/Base.h"


namespace Zero {

class Application {
  public:
    Application() : m_Window { Window::Create({ "Zero", { 1920u, 1080u } }) }
    {
        m_Window->SetEventCallback(Z_BIND_FUNCTION(Application::OnEvent));
        Z_LOG("Application created");
    }

    ~Application()
    {
        Z_LOG("Application destroyed");
    }

  public:
    void Close()
    {
        m_IsRunning = false;
    }

    void Run() const;
    void OnEvent(Event& event);
    bool OnWindowClosed(WindowClosedEvent& event);
    bool OnWindowResized(WindowResizedEvent& event);

  private:
    Scope<Window> m_Window;
    bool m_IsRunning { true };
};
}
