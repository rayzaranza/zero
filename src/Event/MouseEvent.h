#pragma once
#include "Event.h"

#include <glm/glm.hpp>


namespace Zero {


enum class MouseButton : uint8_t
{
    Left,
    Right,
    Middle,
};


class MouseEvent : public Event {
  protected:
    MouseEvent(Type type) : Event { Category::Mouse, type }
    {}
};


class MouseMovedEvent : public MouseEvent {
  public:
    MouseMovedEvent(const glm::vec2& position) : MouseEvent { Type::MouseMoved }, m_Position { position }
    {}

    const glm::vec2& GetPosition() const
    {
        return m_Position;
    }

  private:
    glm::vec2 m_Position;
};


class MouseScrolledEvent : public MouseEvent {
  public:
    MouseScrolledEvent(const glm::vec2& offset) : MouseEvent { Type::MouseScrolled }, m_Offset { offset }
    {}

    const glm::vec2& GetOffset() const
    {
        return m_Offset;
    }

  private:
    glm::vec2 m_Offset;
};


class MouseButtonEvent : public MouseEvent {
  public:
    MouseButtonEvent(MouseButton button, Type type) : MouseEvent { type }, m_Button { button }
    {}

    MouseButton GetButton() const
    {
        return m_Button;
    }

  private:
    MouseButton m_Button;
};


class MouseButtonPressedEvent : public MouseButtonEvent {
  public:
    MouseButtonPressedEvent(MouseButton button) : MouseButtonEvent { button, Type::MouseButtonPressed }
    {}
};


class MouseButtonReleasedEvent : public MouseButtonEvent {
  public:
    MouseButtonReleasedEvent(MouseButton button) : MouseButtonEvent { button, Type::MouseButtonReleased }
    {}
};


}
