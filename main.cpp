#include <iostream>
#include "EventManager.hpp"
#include "Listener.hpp"
#include "RenderWindowListenTarget.hpp"


void foo(SizeEvent::Args args) {
	std::cout << "Burasi foo fonksiyonun icidir." << args.height << " "<< args.width << std::endl;
}

int main() {
	
	try {
		sf::RenderWindow window(sf::VideoMode(800, 600), "Title",sf::Style::Close);
		EventManager em(new Listener(new RenderWindowListenTarget(window)));
		std::cout << em.add<SizeEvent>(foo);

		// event ekleme alternatifi
		em.add<MouseMoveEvent>([](MouseMoveEvent::Args args) {
			// yapýlmasý istenen iþlemler
			std::cout << "Burasi main fonksiyonu icindeki MouseMove eventini takip eden lambda fonksiyonu";
		});

		// event ekleme alternatifi
		em.add<ClosedEvent>([](ClosedEvent::Args args) {
			// yapýlmasý istenen iþlemler
			std::cout << "Burasi main fonksiyonu icindeki Closed eventini takip eden lambda fonksiyonu";
		});
			

		while (window.isOpen()) {
			em.listen();
		}
	}
	catch (const char* ex) {
		std::cout << ex;
	}
	
	
	

	

	system("pause");
	return 0;
}
