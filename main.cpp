#include <iostream>
#include "EventManager.hpp"
#include "Listener.hpp"
#include "RenderWindowListenTarget.hpp"


struct IScene : sf::Drawable {
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;
};

struct Scene : IScene {
	sf::RectangleShape shape;
	EventManager* em;
	Scene() : em(0){	}

	void start() {
		shape.setSize(sf::Vector2f(100, 50));
		shape.setFillColor(sf::Color::Red);
		em->add<SizeEvent>(foo);
	}

	static void foo(SizeEvent::Args args) {
		std::cout << args.height << std::endl;
	}

	void update() {
		shape.move(sf::Vector2f(1, 0));
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states)const {
		target.clear(sf::Color::Blue);
		target.draw(shape);
	}
};

class Application {
	static sf::RenderWindow window;
	EventManager em;
	IScene* active;
public:
	Application(sf::Vector2u size,std::string Title) 
		: em(new Listener(new RenderWindowListenTarget(window))) {
		window.create(sf::VideoMode(size.x, size.y), "Title");
		
	}

	void mainloop() {
		while (window.isOpen()) {
			window.draw(*active);
			active->update();
			window.display();
			em.listen();
		}
	}

	EventManager* getEventManager() {
		return &em;
	}

	void setScene(IScene* scene) {
		active = scene;
		scene->start();
	}
};

sf::RenderWindow Application::window;
void foo(SizeEvent::Args args) {
	std::cout << "Foo" << args.height << " "<< args.width << std::endl;
}

int main() {
	Application app(sf::Vector2u(800, 600), "Deneme");
	Scene scene;
	scene.em = app.getEventManager();
	app.setScene(&scene);
	app.mainloop();

	/*
	try {
		sf::RenderWindow window(sf::VideoMode(800, 600), "Title",sf::Style::Close);
		EventManager em(new Listener(new RenderWindowListenTarget(window)));
		std::cout << em.add<SizeEvent>(foo);
		em.add<MouseMoveEvent>([](MouseMoveEvent::Args args) {
			std::cout << "Mouse Move";
		});

		em.add<ClosedEvent>([](ClosedEvent::Args args) {
			std::cout << "kapatmiyorum";
		});
			

		while (window.isOpen()) {
			em.listen();
		}
	}
	catch (const char* ex) {
		std::cout << ex;
	}
	*/
	
	

	

	system("pause");
	return 0;
}
