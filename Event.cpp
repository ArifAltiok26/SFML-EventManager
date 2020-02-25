#include "Event.hpp"

Event::Event(sf::Event::EventType type)
	: type(type)
{	}

ClosedEvent::ClosedEvent()
	: HardwareEvent(sf::Event::Closed)
{	}


LostFocusEvent::LostFocusEvent()
	: HardwareEvent(sf::Event::LostFocus)
{	}

GainedFocusEvent::GainedFocusEvent()
	: HardwareEvent(sf::Event::GainedFocus)
{	}


SizeEvent::SizeEvent()
	: SoftwareEvent(sf::Event::Resized)
{	}


MouseMoveEvent::MouseMoveEvent()
	:	SoftwareEvent(sf::Event::MouseMoved)
{	}
	

MousePressedEvent::MousePressedEvent()
	: SoftwareEvent(sf::Event::MouseButtonPressed)
{	}


MouseReleasedEvent::MouseReleasedEvent()
	: SoftwareEvent(sf::Event::MouseButtonReleased)
{	}


KeyPressedEvent::KeyPressedEvent()
	: SoftwareEvent(sf::Event::KeyPressed)
{	}

KeyReleasedEvent::KeyReleasedEvent()
:SoftwareEvent(sf::Event::KeyReleased)
{	}