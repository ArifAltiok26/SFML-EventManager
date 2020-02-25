#pragma once
class IListenSource;
class IListenTarget {
public:
	virtual ~IListenTarget() {	}

	virtual bool listen() const = 0;
	// Dinlenen yerde deðiþiklik varsa true döner
	// Tüm alt sýnýflar nasýl dinleme yapmak isterse override eder
	
	virtual IListenSource* getListenSource() const = 0;
	// dinlemenin kaynaðýný döndürür -> (bellek üzerinde iþlemler)
	// bkz. IListenSource.hpp
};



