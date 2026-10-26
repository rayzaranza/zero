#include "Application.h"
#include "../Logger/Logger.h"
#include "../Event/EventDispatcher.h"
#include "../Event/AppEvent.h"
#include "../Core/Base.h"


void Zero::Application::Run() const
{
    while (m_IsRunning) {
        m_Window->Update();
    }
}


void Zero::Application::OnEvent(Event& event)
{
    EventDispatcher dispatcher { event };
    dispatcher.Dispatch<WindowClosedEvent>(Z_BIND_FUNCTION(Application::OnWindowClosed));
    dispatcher.Dispatch<WindowResizedEvent>(Z_BIND_FUNCTION(Application::OnWindowResized));
}


bool Zero::Application::OnWindowClosed(WindowClosedEvent& event)
{
    m_IsRunning = false;
    return true;
}


bool Zero::Application::OnWindowResized(WindowResizedEvent& event)
{
    m_Window->Resize(event.GetSize());
    return true;
}
