#pragma once
#include <vector>
#include <functional>
#include <SFML/Window/Event.hpp>
namespace sf{
    class Window;
}

using Callback = std::function<void(const sf::Event&)>;
using Callbacks = std::vector<Callback>;

class EventManager{
	sf::Window& window;
	std::vector<sf::Event::EventType> events;
	std::vector<Callbacks> callbacks_container;
	public:

	EventManager(sf::Window& window);

    static void nothings_callback(const sf::Event&);

	void listen()const;

	void add(const sf::Event::EventType&, const Callback& callback = nothings_callback);
};