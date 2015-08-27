#ifndef __MYUN2_GITHUB_COM__MEMORIZE5__MEMORY_ALLOCATOR_HPP__
#define __MYUN2_GITHUB_COM__MEMORIZE5__MEMORY_ALLOCATOR_HPP__

#include <memory.h>

namespace myun2
{
	namespace memorize
	{
		class memory_allocator
		{
		private:
			unsigned char* buffer;
		public:
			memory_allocator(unsigned long size) { allocate(size); }
			void allocate(unsigned long size)
			{
				buffer = new unsigned char[size];
			}
			void write(unsigned long addr, const void* data, unsigned long size) {
				memcpy(buffer + addr, data, size);
			}
			void read(unsigned long addr, void* data, unsigned long size) {
				memcpy(data, buffer + addr, size);
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__MEMORIZE5__MEMORY_ALLOCATOR_HPP__
