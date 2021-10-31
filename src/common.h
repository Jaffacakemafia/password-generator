
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>




#define DEBUG 1
#define debug_print(fmt, ...) \
        do { if (DEBUG) fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, \
                                __LINE__, __func__, __VA_ARGS__); } while (0)




char* toLower(char* inString)
{
	debug_print("in string: %s\n", inString);
	size_t stringLength = strnlen(inString, (size_t)32);
	for (size_t x = 0; x < stringLength; x++)
	{

		if (((int) inString[x] >= 65) && ((int)inString[x] <= 90))
		{
			inString[x] = (char) (32 + (int) inString[x]);
		}
	}
	debug_print("out string: %s\n", inString);
	return inString;
}
