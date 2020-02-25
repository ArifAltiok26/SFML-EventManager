#pragma once
#include "Handle.hpp";

/*
	- Handle sýnýfýný geniþletir.
	
	- Fonksiyonlarý tutmak için kullanýlýr.
	
	- Tutulacak fonksiyonun parametre tipi Args olarak,
	  geri dönüþ tipi Retval olarak belirtilir.

	- bkz. Handle.hpp
    - Kullanýmlar için bakýnýz FunctionTrigger.hpp
*/

template<typename Args, typename Retval>
class FunctionHandle : public Handle {
public:
	using FunctionType = Retval(Args);
	using Function = std::function<FunctionType>;
	FunctionHandle(FunctionType function);
	const Function function;
	Retval operator()(Args args);
};

template<typename Args, typename Retval>
FunctionHandle<Args, Retval>::FunctionHandle(
		FunctionHandle<Args,Retval>::FunctionType function)
	: function(function)
{	}

template<typename Args, typename Retval>
Retval FunctionHandle<Args,Retval>::operator()(Args args) {
	return function(args);
}