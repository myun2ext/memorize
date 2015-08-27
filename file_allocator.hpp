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
			file_allocator(const char* file) { open(file); }
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
			unsigned long size() {
				fseek(fp, 0, SEEK_END);
				return ftell(fp);
			}
			void write(unsigned long addr, const void* data, unsigned long size) {
				fseek(fp, addr, SEEK_SET);
				fwrite(data, size, 1, fp);
			}
			unsigned long add(const void* data, unsigned long size) {
				fseek(fp, 0, SEEK_END);
				unsigned long p = ftell(fp);
				fwrite(data, size, 1, fp);
				return p;
			}
			void read(unsigned long addr, void* data, unsigned long size) {
				fseek(fp, addr, SEEK_SET);
				fread(data, size, 1, fp);
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__MEMORIZE5__FILE_ALLOCATOR_HPP__
