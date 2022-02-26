#include "EventManager.hpp"
#include <iostream>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>

EventManager::EventManager(sf::Window& window) : window(window){	}

void EventManager::nothings_callback(const sf::Event&){
	std::cout << "Here is nothings" << std::endl;
}

void EventManager::listen()const{
    sf::Event event;
    if(window.pollEvent(event)){
        for(size_t i = 0;i < events.size();i++){
            if(events[i] == event.type){
                for(auto callback : callbacks_container[i]){
                    callback(event);
                }
            }
        }
    }		
}

void EventManager::add(const sf::Event::EventType& event, const Callback& callback){
    std::vector<sf::Event::EventType>::const_iterator iter = events.begin();
    while(iter != events.end() && *iter != event){
        iter++;
    }
    if(iter != events.end()){
        size_t index = iter - events.begin();
        callbacks_container[index].push_back(callback);
    }
    else{
        events.push_back(event);
        Callbacks callbacks;
        callbacks.push_back(callback);
        callbacks_container.push_back(callbacks);
    }
}