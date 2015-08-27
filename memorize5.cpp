#include <stdio.h>
#include "memory_allocator.hpp"
#include "file_allocator.hpp"

using namespace myun2::memorize;

int main()
{
	file_allocator f("test.db");
	unsigned long p = f.add("test.\0", 6);

	char buf[5];
	f.read(p, buf, 6);
	printf("[%d] %s\n", p, buf);

	return 0;
}
