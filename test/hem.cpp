#include <stdio.h>
#include "memorize/buffer.hpp"

int main()
{
	using namespace myun2::memorize;
	buffer b("init", 5, 100);
	b.realloc(1000);
	return 0;
}
