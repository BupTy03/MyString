#include "mystring.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

MyString* newMyStringOfSize(int size)
{
	assert(size > 0);

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

static int isInRange(int index, int rangeSize)
{
	return (int)(index >= 0 && index < rangeSize);
}

char getCharAtMyString(MyString* myString, int index)
{
	assert(myString);
	assert(isInRange(index, sizeOfMyString(myString)));
	return myString->data[index];
}
void setCharAtMyString(MyString* myString, int index, char val)
{
	assert(index >= 0 && index < sizeOfMyString(myString));
	myString->data[index] = val;
}

MyString* subStrOfMyString(MyString* myString, int beginIndex, int endIndex)
{
	assert(isInRange(beginIndex, sizeOfMyString(myString)));
	assert(isInRange(endIndex, sizeOfMyString(myString)));

	const int newStringSize = endIndex - beginIndex;
	MyString* pResult = newMyStringOfSize(newStringSize);
	assert(pResult);

	memcpy(pResult->data, (myString->data + beginIndex), newStringSize);
	return pResult;
}

MyString* cloneMyString(MyString* myString)
{
	return subStrOfMyString(myString, 0, sizeOfMyString(myString));
}

MyString* concatenateMyStrings(MyString* leftString, MyString* rightString)
{
	assert(leftString);
	assert(rightString);

	const int sizeOfLeftStr = sizeOfMyString(leftString);
	const int sizeOfRightStr = sizeOfMyString(rightString);
	assert(sizeOfLeftStr >= 0);
	assert(sizeOfRightStr >= 0);

	if(0 == sizeOfLeftStr)
		return cloneMyString(rightString);
	if(0 == sizeOfRightStr)
		return cloneMyString(leftString);

	const int sizeOfResultStr = sizeOfLeftStr + sizeOfRightStr;
	MyString* pResult = newMyStringOfSize(sizeOfResultStr);
	assert(pResult);

	memcpy(pResult->data, leftString->data, sizeOfLeftStr);
	memcpy(pResult->data + sizeOfLeftStr, rightString->data, sizeOfResultStr);

	return pResult;
}

void deleteMyString(MyString* myString)
{
	assert(myString);
	assert(myString->data);

	char* ptr = myString->data - MY_STRING_HEADER_SIZE;
	assert(ptr);
	free(ptr);

	free(myString);
}