#include <stdio.h>
#include "memory_allocator.hpp"
#include "file_allocator.hpp"

using namespace myun2::memorize;

int main()
{
	file_allocator f("test.db");
	f.write(0, "test", 4);
	return 0;
}
