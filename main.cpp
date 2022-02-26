#include <iostream>
#include "SFML/Graphics.hpp"
#include "EventManager.hpp"

void MouseButtonPressed_Callback(const sf::Event& args){
	std::cout 	<< "Here is in function of MouseButtonPressed_Callback. " 
				<< args.mouseButton.button << " "
				<< args.mouseButton.x << " "
				<< args.mouseButton.y << std::endl;
}


int main() {
	sf::RenderWindow window(sf::VideoMode(800,600), "Test");
	EventManager em(window);
	em.add(sf::Event::KeyPressed,[](const sf::Event& event ){
		std::cout <<"Key Event->code: " <<  event.key.code << std::endl;
	});

	em.add(sf::Event::MouseEntered);// default nothings
	
	em.add(sf::Event::MouseButtonPressed, MouseButtonPressed_Callback);

	em.add(sf::Event::Closed,[&](const sf::Event&){
		window.close();
	});

	while(window.isOpen()){
		em.listen();
		window.clear();
		window.display();
	}

	return 0;
}