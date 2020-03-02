#include <stdio.h>

#include<string.h>

void main(void)
{
	char myString[] = "This is my first string.";
	char *myStringPtr = myString;

	int count = 0;

	puts("\n");

	while (*myStringPtr != '\0')
	{
		printf("%c", *myStringPtr);
		myStringPtr++;
		count += 1;
	}

	printf("\n\nCount of char in myString is %d. \n\n", count);

	printf("\n\nUsing the C function \"strlen()\" string length is %d. \n\n", strlen(myString));
}