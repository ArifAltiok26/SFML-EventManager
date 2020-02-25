#pragma once
#include "ListenSource.hpp"
#include <SFML/Graphics.hpp>
/*
	- Sýnýf özelleþtirmesidir.
	- sfml sf::Event sýnýfýný sisteme adapte eder.
	
	- bkz. IListenSource.hpp
*/
class RenderWindowListenSource : public ListenSource<sf::Event> {
public:
	using ListenSource<sf::Event>::ListenSource;
	void* getEventMemory()const;
	void* getDataMemory()const;
};

