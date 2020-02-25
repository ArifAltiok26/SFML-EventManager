#include "Handle.hpp"

Handle::Handle() : id(identifer++) {	}

Handle::~Handle()
{	}

size_t Handle::identifer = 1;
