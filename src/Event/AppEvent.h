#pragma once
#include "Event.h"
#include <glm/glm.hpp>


namespace Zero {


class AppEvent : public Event {
  protected:
    explicit AppEvent(Type type) : Event { Category::App, type }
    {}
};


class WindowResizedEvent : public AppEvent {
  public:
    explicit WindowResizedEvent(const glm::ivec2& size) : AppEvent { GetStaticType() }, m_Size { size }
    {}

    static constexpr Type GetStaticType() noexcept
    {
        return Type::WindowResized;
    }

    const glm::ivec2& GetSize() const
    {
        return m_Size;
    }

  private:
    glm::ivec2 m_Size;
};


class WindowClosedEvent : public AppEvent {
  public:
    WindowClosedEvent() : AppEvent { GetStaticType() }
    {}

    static constexpr Type GetStaticType() noexcept
    {
        return Type::WindowClosed;
    }
};


class AppTickedEvent : public AppEvent {
  public:
    AppTickedEvent() : AppEvent { GetStaticType() }
    {}

    static constexpr Type GetStaticType() noexcept
    {
        return Type::AppTicked;
    }
};


class AppUpdatedEvent : public AppEvent {
  public:
    AppUpdatedEvent() : AppEvent { GetStaticType() }
    {}

    static constexpr Type GetStaticType() noexcept
    {
        return Type::AppUpdated;
    }
};


class AppRenderedEvent : public AppEvent {
  public:
    AppRenderedEvent() : AppEvent { GetStaticType() }
    {}

    static constexpr Type GetStaticType() noexcept
    {
        return Type::AppRendered;
    }
};
}
