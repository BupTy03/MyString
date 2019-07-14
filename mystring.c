#include "mystring.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

MyString* newMyStringOfSize(int size)
{
	MyString* resultString = (MyString*)malloc(sizeof(MyString));

	char* pChars = (char*)calloc((MY_STRING_HEADER_SIZE + size + 1), sizeof(char));

	int* pHeader = (int*)pChars;
	*pHeader = size;

	pChars[MY_STRING_HEADER_SIZE + size] = '\0';

	resultString->data = pChars + MY_STRING_HEADER_SIZE;
	return resultString;
}
MyString* newMyStringFromCStr(const char* c_str)
{
	assert(c_str);
	const int strSize = strlen(c_str);
	MyString* pMyString = newMyStringOfSize(strSize);

	assert(pMyString->data);
	memcpy(pMyString->data, c_str, strSize);
	return pMyString;
}

int sizeOfMyString(MyString* myString)
{
	assert(myString);
	assert(myString->data);
	return *((int*)(myString->data - MY_STRING_HEADER_SIZE));
}
int isMyStringEmpty(MyString* myString)
{
	return (int)(sizeOfMyString(myString) > 0);
}
char getCharAtMyString(MyString* myString, int index)
{
	assert(index >= 0 && index < sizeOfMyString(myString));
	return myString->data[index];
}
void setCharAtMyString(MyString* myString, int index, char val)
{
	assert(index >= 0 && index < sizeOfMyString(myString));
	myString->data[index] = val;
}

void deleteString(MyString* myString)
{
	assert(myString);
	assert(myString->data);

	char* ptr = myString->data - MY_STRING_HEADER_SIZE;
	assert(ptr);
	free(ptr);

	free(myString);
}