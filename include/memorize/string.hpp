#ifndef __MYUN2_GITHUB_COM__MEMORIZE_STRING_HPP__
#define __MYUN2_GITHUB_COM__MEMORIZE_STRING_HPP__

#include <memory.h>
#include <stdlib.h>

namespace myun2 {
	namespace memorize {
		template <typename T>
		struct string
		{
			unsigned long size;
			T* ptr;
			buffer() {
				ptr = 0;
				size = 0;
			}
			buffer(unsigned long initial_size) {
				ptr = 0;
				alloc(initial_size);
			}
			buffer(const void* initial_data, unsigned long length, unsigned long initial_size=0) {
				ptr = 0;
				if (initial_size < length)
					initial_size = length;
				alloc(initial_size);
				memcpy(ptr, initial_data, length);
			}
			virtual ~buffer() { free(); }
			void free() {
				if (ptr) {
					::free(ptr);
					ptr = 0;
					size = 0;
				}
			}
			void alloc(unsigned long size_in) {
				free();
				size = size_in;
				ptr = calloc(size, 1);
			}
			void resize(unsigned long new_size) {
				ptr = ::realloc(ptr, new_size);
				size = new_size;
			}
			void realloc(unsigned long new_size) { resize(new_size); }
		};
	}
}
#endif//__MYUN2_GITHUB_COM__MEMORIZE_STRING_HPP__
