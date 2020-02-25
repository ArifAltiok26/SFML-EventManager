#pragma once
#include "FunctionTrigger.hpp"
#include "EventFunctionHandle.hpp"

/*
	- Sýnýf özelleþtirmesidir
	  Event tiplerine göre alacaðý Args ve 
	  Retval tiplerini otomatik belirlenir. 
	  Sadece Eventin tipi belirtilmesi yeterlidir.
	  
	- Diðer kullanýmlar için bkz. FunctionTrigger.hpp

*/
template<typename Event>
using EventFunctionTrigger =
FunctionTrigger<
	typename EventTraits<Event>::Args,
	typename EventTraits<Event>::Retval>;

