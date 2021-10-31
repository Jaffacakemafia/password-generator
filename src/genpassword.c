#include "common.h"



int main(int argc, char* argv[])
{
	#define DEFAULT_PASSWORD_LENGTH  16  
	const int MIN_ASCII_INT = 33;
	const int MAX_ASCII_INT = 126;
	int passwordLength = DEFAULT_PASSWORD_LENGTH;

	if(argc >= 2) 
	{
		for (int currentArg = 1; currentArg < argc; currentArg++)
		{
			debug_print("Current argument: %s\n", argv[currentArg]);
			if ((strcmp(toLower(argv[currentArg]), "-length") == 0) ||
				(strcmp(toLower(argv[currentArg]), "-ln") == 0))
			{
				currentArg++;
				passwordLength = atoi(argv[currentArg]);  //Check for int
				debug_print("Setting password length to: %d\n", passwordLength);
			} 
			else
			{
				printf("Invalid argument.  Skipping argument: %s\n", argv[currentArg]);
			}
		}
	}

	
	char* password = (char*)malloc((passwordLength + 1) * sizeof(char));
	if (password == NULL) {
		printf("Memory not allocated for password.\n");
		exit(0);
	}

	srand((unsigned int)time(NULL)); //Typecast to a 32bit int as system may return 64bit int
	
	for (int x = 0; x < passwordLength; x++)
	{
		//Get a random chacter between 
		char randomChar = (char) (rand() % (MAX_ASCII_INT - MIN_ASCII_INT + 1)) + MIN_ASCII_INT;
		debug_print("Generated random character: %c\n", randomChar);
		password[x] = randomChar;
	}
	password[passwordLength] = '\0';  //Terminate generated string with null character

	printf("Password generated:  %s\n", password);
	free(password);
	return 0;
}

