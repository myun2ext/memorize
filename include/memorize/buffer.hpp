#ifndef __MYUN2_GITHUB_COM__MEMORIZE_BUFFER_HPP__
#define __MYUN2_GITHUB_COM__MEMORIZE_BUFFER_HPP__

#include <memory.h>
#include <stdlib.h>

namespace myun2 {
	namespace memorize {

		struct buffer
		{
			void* ptr;
			unsigned long size;
			buffer() {
				ptr = 0;
				size = 0;
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
#endif//__MYUN2_GITHUB_COM__MEMORIZE_BUFFER_HPP__
