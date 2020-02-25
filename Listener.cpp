#include "Listener.hpp"

#include "IListenTarget.hpp"
#include "Handle.hpp"

Listener::Listener(IListenTarget* target)
	: target(target)
{	}

bool Listener::listen() {
	return target->listen();
}

IListenSource* Listener::getListenSource()const { return target->getListenSource(); }
