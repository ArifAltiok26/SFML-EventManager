#include "RenderWindowListenSource.hpp"

void* RenderWindowListenSource::getEventMemory()const {
	return static_cast<void*>(&source);
}

void* RenderWindowListenSource::getDataMemory()const {
	return static_cast<void*>(&source.size);
}