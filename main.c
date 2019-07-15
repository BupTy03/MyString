#include "mystring.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	MyString* str = newMyStringFromCStr("Hello world!");
	setCharAtMyString(str, 0, 'D');

	printf("Size of str is: %d\n", sizeOfMyString(str));
	printf("Str: %s\n", str->data);

	MyString* subStr = subStrOfMyString(str, 2, 6);
	printf("SubStr[2:6): %s\n", subStr->data);

	MyString* leftStr = newMyStringFromCStr("Hello ");
	MyString* rightStr = newMyStringFromCStr("world!");

	MyString* concatenatedStr = concatenateMyStrings(leftStr, rightStr);
	printf("Concatenated str: %s\n", concatenatedStr->data);

	deleteMyString(subStr);
	deleteMyString(str);
	deleteMyString(leftStr);
	deleteMyString(rightStr);
	return(0);
}