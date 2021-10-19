#include "common.h"



int main()
{
	#define PASSWORD_LENGTH  16  
	const int MIN_ASCII_INT = 33;
	const int MAX_ASCII_INT = 126;

	char password[PASSWORD_LENGTH] = "";
	

	printf("Password generated: ");

	srand((unsigned int)time(NULL)); //Typecast to a 32bit int as system may return 64bit int
	
	for (int x = 0; x < PASSWORD_LENGTH; x++) {

		char randomChar = (char) (rand() % (MAX_ASCII_INT - MIN_ASCII_INT + 1)) + MIN_ASCII_INT;
		strncat(password, &randomChar, 1);
	}
	
	printf("%s\n", password);

	getchar();
	return 0;
}
