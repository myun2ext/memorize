#include <stdio.h>
#include "memory_allocator.hpp"
#include "file_allocator.hpp"

using namespace myun2::memorize;

int main()
{
	file_allocator f("test.db");
	f.write(10, "test.\0", 6);

	char buf[5];
	f.read(10, buf, 6);
	printf("%s\n", buf);

	return 0;
}
