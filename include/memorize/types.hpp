#ifndef __MYUN2_GITHUB_COM__MEMORIZE_TYPES_HPP__
#define __MYUN2_GITHUB_COM__MEMORIZE_TYPES_HPP__

#include <memory.h>
#include <stdlib.h>

namespace myun2 {
	namespace memorize {
		namespace types {
			enum types
			{
				null_type = 0,
				char_type = 1,
				nano_string_type = 2,	//	4byte
				micro_string_type,		//	8byte
				mini_string_type,		//	16byte
				short_string_type,		//	32byte
				medium_string_type,		//	64byte
				string_type,			//	128byte
				large_string_type,		//	256byte

				char_type = 24,
				u_char_type = 25,

				short_type = 26,
				u_short_type = 27,
				integer_type = 28,
				u_int_type = 29,
				long_int_type = 30,
				u_long_int_type = 31,

				float_type = 60,
				double_type = 61,

				_term = 256
			};
		}
	}
}
#endif//__MYUN2_GITHUB_COM__MEMORIZE_TYPES_HPP__
