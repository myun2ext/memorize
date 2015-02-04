#include <stdio.h>
#include "memorize/buffer.hpp"

int main()
{
	using namespace myun2::memorize;
	buffer b;
	b.alloc(30);
	b.realloc(100);
	b.free();
	return 0;
}
