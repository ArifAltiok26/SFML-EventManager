#include "EventManager.hpp"

EventManager::EventManager(IListener* listener) : listener(listener) {	}

void EventManager::remove(size_t id) {
	for (Hash* hash : hashes) {
		if (hash->trigger->remove(id))
			break;
	}
}

void EventManager::listen() {
	if (listener->listen()) {
		IListenSource* source = listener->getListenSource();
		for (Hash* hash : hashes) {
			if (!memcmp(&hash->event, source, sizeof(hash->event)))
				hash->trigger->triggered();
		}
	}
}
