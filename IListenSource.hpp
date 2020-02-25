#pragma once

/*
	Dinleme hedeflerinin kaynak arayüzüdür.
	Yani hedef dinleyerek sonuçlarýný kaynaðýna yazar

*/
class IListenSource {
public:
	virtual void* getEventMemory()const = 0;
	// bellek üzerinde event datalarý karþýlaþtýrmak için
	
	virtual void* getDataMemory()const = 0;
	// bellek üzerinden beklenen event ile ilgili args alabilmek için
};

