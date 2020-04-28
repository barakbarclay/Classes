//
//		anotherStringPointer
//
#include <stdio.h>

void main(void)
{
	char stringofchar[] = "This is a string, or an array of char.";
	char *stringofcharPtr = stringofchar; //don't need a "&" because the name of the array is an address

	size_t k;

	printf("\n\nThe starting address of the array of chqar is %p \n", stringofchar);
	printf("\n\nThe address in the pointer is %p \n\n", stringofcharPtr);

	//How to print a string//
	printf("%c", *stringofcharPtr);
	puts("\n");

	printf("%s", stringofcharPtr);
	puts("\n");
	printf("%s", stringofchar);
	puts("\n");

	//write a loop to print one char at a time//

	puts("\nLoop to print array of char. \n");
	while (*stringofcharPtr != '\0')
	{
		printf("%c", *stringofcharPtr);
		stringofcharPtr++; //will only print T's without this line		//must use Ptr
	}
	puts("\n");
	printf("\n\nThe ending address of the sting pointer is %p \n", stringofcharPtr);

	printf("%s", stringofcharPtr);//doesn't print anything because it points to the end of string designator

	k = 38;
	while (k != 0)//this loop prints the string backwards
	{
		stringofcharPtr--;
		printf("%c", *stringofcharPtr);
		k--;
	}
	puts("\n");
}