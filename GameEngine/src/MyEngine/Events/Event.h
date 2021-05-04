#pragma once

#include "MyEngine/Core.h"

namespace MyEngine {
	// Events in MyEngine are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there.
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.


	// Event Types, ids for every event type
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, // Application Events
		//AppTick, AppUpdate, AppRender, // Application Events
		KeyPressed, KeyReleased, // Key Events
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled // Mouse Events
	};

	// Categories of Event Types
	// Bit shifting is used, so we can apply multiple categories to an event
	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};


	// define to not have to copy those functions to all event classes
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }



	class MY_ENGINE_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		// Returns if the event is in the given category
		bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

		bool m_Handled = false; // to check if an event hase been handled and we want to discard it (e. g. mouse click)
	};


	class MY_ENGINE_API EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) // create event dispatcher with event
			: m_Event(event) {

		}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticType()) { // checking which event type the event is and if it matches the template argument
				m_Event.m_Handled |= func(*(T*)&m_Event); // call function with event
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}