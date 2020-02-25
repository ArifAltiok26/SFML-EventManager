#pragma once
#include "IListenSource.hpp";

class IListener {
public:
	virtual bool listen() = 0;
	// dinleyici dinleme kurallarýný belirler
	// deðiþiklik durumunda true deðer döndürmesi beklenir

	virtual IListenSource* getListenSource()const = 0;
	// dinlemenin kaynaðýný döndürür -> (bellek üzerinde iþlemler)
	// bkz. IListenSource.hpp
};