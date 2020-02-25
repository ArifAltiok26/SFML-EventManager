#pragma once
#include "ListenTarget.hpp"
#include <SFML/Graphics.hpp>
/*
	- Sýnýf özelleþtirmesidir.
	- sfml sf::RenderWindow sýnýfýný sisteme adapte eder.

	- bkz. IListenTarget.hpp
*/

class RenderWindowListenTarget : public ListenTarget<sf::RenderWindow> {
	IListenSource* source;
	mutable sf::Event event;
public:
	RenderWindowListenTarget(sf::RenderWindow& window);
	//override
	bool listen()const;
	//override
	IListenSource* getListenSource()const;
};