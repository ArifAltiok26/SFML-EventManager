#pragma once
#include "IListener.hpp"
class IListenTarget;
/*
	Dinleme Hedefi ile kaynaðý arasýnda bað kurulup dinleme iþlemi yapýlýr

	bkz. IListener.hpp
*/

class Listener : public IListener {
	IListenTarget* target;
public:
	Listener(IListenTarget* target);

	//override
	bool listen();
	//override
	IListenSource* getListenSource()const;
};
