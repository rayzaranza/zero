#pragma once
#include <cstdint>


namespace Zero {


class Event {
  public:
    enum class Category : std::uint8_t
    {
        None = 0,
        App = 1 << 0,
        Input = 1 << 1,
        Keyboard = 1 << 2,
        Mouse = 1 << 3,
        MouseButton = 1 << 4,
    };

    enum class Type : std::uint8_t
    {
        None,
        WindowClosed,
        WindowResized,
        WindowFocused,
        WindowLostFocus,
        WindowMoved,
        AppTicked,
        AppUpdated,
        AppRendered,
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled,
    };

  protected:
    Event(Category category, Type type) : m_Category { category }, m_Type { type }
    {}

  public:
    virtual ~Event() = default;

  public:
    Category GetCategory() const
    {
        return m_Category;
    }

    Type GetType() const
    {
        return m_Type;
    }

    bool IsInCategory(Category category) const
    {
        return static_cast<std::uint8_t>(GetCategory()) & static_cast<std::uint8_t>(category);
    }

    bool GetIsHandled() const
    {
        return m_IsHandled;
    }

    void SetIsHandled(bool isHandled)
    {
        m_IsHandled = isHandled;
    }

  private:
    Category m_Category;
    Type m_Type;
    bool m_IsHandled { false };
};


}
