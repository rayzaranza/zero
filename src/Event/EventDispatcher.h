#pragma once
#include "Event.h"


namespace Zero {


class EventDispatcher {
  public:
    EventDispatcher(Event& event) : m_Event { event }
    {}

  public:
    template <typename TEvent, typename TFunction>
    bool Dispatch(const TFunction& function)
    {
        if (m_Event.GetType() == TEvent::GetStaticType()) {
            m_Event.SetIsHandled(function(static_cast<TEvent&>(m_Event)));
            return true;
        }

        return false;
    }

  private:
    Event& m_Event;
};


}
