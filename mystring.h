#ifndef MY_STRING_H
#define MY_STRING_H

typedef struct MyString {
	char* data;
} MyString;

enum { MY_STRING_HEADER_SIZE = sizeof(int) / sizeof(char) };

MyString* newMyStringOfSize(int size);
MyString* newMyStringFromCStr(const char* c_str);

int sizeOfMyString(MyString* myString);
int isMyStringEmpty(MyString* myString);

char getCharAtMyString(MyString* myString, int index);
void setCharAtMyString(MyString* myString, int index, char val);

MyString* subStrOfMyString(MyString* myString, int beginIndex, int endIndex);
MyString* cloneMyString(MyString* myString);

MyString* concatenateMyStrings(MyString* leftString, MyString* rightString);

void deleteMyString(MyString* myString);


#endif // !MY_STRING_H
