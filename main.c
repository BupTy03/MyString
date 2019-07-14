#include "mystring.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	MyString* str = newMyStringFromCStr("Zarova!");
	setCharAtMyString(str, 0, 'D');

	printf("Size of str is: %d\n", sizeOfMyString(str));
	printf("Str: %s\n", str->data);

	deleteString(str);
	return(0);
}