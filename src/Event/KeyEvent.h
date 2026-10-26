#pragma once
#include "Event.h"
#include "../Input/KeyCode.h"


namespace Zero {


class KeyEvent : public Event {
  protected:
    KeyEvent(KeyCode event, Type type) : Event { Category::Keyboard, type }
    {}

  public:
    KeyCode GetKeyCode() const
    {
        return m_KeyCode;
    }

  private:
    KeyCode m_KeyCode;
};


class KeyPressedEvent : public KeyEvent {
  public:
    KeyPressedEvent(KeyCode keyCode, int repeatCount) : KeyEvent { keyCode, Type::KeyPressed }, m_RepeatCount { repeatCount }
    {}

    int GetRepeatCount() const
    {
        return m_RepeatCount;
    }

  private:
    int m_RepeatCount;
};


class KeyReleasedEvent : public KeyEvent {
  public:
    KeyReleasedEvent(KeyCode keyCode) : KeyEvent { keyCode, Type::KeyReleased }
    {}
};


class KeyTypedEvent : public KeyEvent {
  public:
    KeyTypedEvent(KeyCode keyCode) : KeyEvent { keyCode, Type::KeyTyped }
    {}
};
}
