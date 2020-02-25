#pragma once
#include "FunctionHandle.hpp"
/*
	- Sýnýf özelleþtirmesidir
	  Event tiplerine göre alacaðý Args ve
	  Retval tiplerini otomatik belirlenir.
	  Sadece Eventin tipi belirtilmesi yeterlidir.

	- Diðer kullanýmlar için bkz. FunctionHandle.hpp

*/
template<typename Event>
using EventFunctionHandle =
FunctionHandle<
	typename EventTraits<Event>::Args,
	typename EventTraits<Event>::Retval>;
