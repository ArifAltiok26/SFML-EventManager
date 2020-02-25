#pragma once
#include "IListenSource.hpp"
/*
	- Sýnýf özelleþtirmeleri için kullanýlabilir template sýnýf

	- bkz. IListenSource.hpp
*/
template<typename Source>
class ListenSource : public IListenSource {
protected:
	Source& source;
public:
	ListenSource(Source& source) : source(source) {}
	virtual void* getEventMemory() const = 0;
	virtual void* getDataMemory() const = 0;
};