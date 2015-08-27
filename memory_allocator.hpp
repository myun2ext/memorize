#ifndef __MYUN2_GITHUB_COM__MEMORIZE5__MEMORY_ALLOCATOR_HPP__
#define __MYUN2_GITHUB_COM__MEMORIZE5__MEMORY_ALLOCATOR_HPP__

namespace myun2
{
	namespace memorize
	{
		class memory_allocator
		{
		private:
			void* buffer;
		public:
			memory_allocator(unsigned long size) : allocate(size) {}
			void allocate(const char* size)
			{
				buffer = new unsigned char[size];
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__MEMORIZE5__MEMORY_ALLOCATOR_HPP__
