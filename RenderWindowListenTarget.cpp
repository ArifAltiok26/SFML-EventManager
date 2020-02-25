#include "RenderWindowListenTarget.hpp"
#include "RenderWindowListenSource.hpp"


RenderWindowListenTarget::RenderWindowListenTarget(sf::RenderWindow& window)
	: ListenTarget<sf::RenderWindow>(window) {
	source = new RenderWindowListenSource(event);
}

bool RenderWindowListenTarget::listen()const {
	bool retval = target.pollEvent(event);
	if (retval) {
		memcpy(source, &event, sizeof(event));
	}
	return retval;
}

IListenSource* RenderWindowListenTarget::getListenSource()const {
	return source;
}