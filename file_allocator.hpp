#ifndef __MYUN2_GITHUB_COM__MEMORIZE5__FILE_ALLOCATOR_HPP__
#define __MYUN2_GITHUB_COM__MEMORIZE5__FILE_ALLOCATOR_HPP__

#include <stdio.h>
#ifdef WIN32
	#include <io.h>
	#pragma warning (disable:4996)
	#define access _access
#else
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/stat.h>
#endif

namespace myun2
{
	namespace memorize
	{
		class file_allocator
		{
		private:
			FILE* fp;
		public:
			file_allocator(const char* file) : open(file) {}
			bool open(const char* file)
			{
				if ( access(file, 0) )
					fp = fopen(file, "w+b");
				else {
					fp = fopen(file, "r+b");
					if ( fp != NULL) fseek(fp, 0, SEEK_END);
				}
				return fp != NULL;
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__MEMORIZE5__FILE_ALLOCATOR_HPP__