/*
*  encode.c
*  lecture-code to encode a character using a +1 Caesar cipher shift
*
*  Author: Richard Buckland on 16/03/11, 20/11/12.
*  Licensed under Creative Commons SA-BY-NC 3.0.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "encode.h"



int main(int argc, char *argv[]) 
{

	testEncode();

	char plainChar;
	char encodedChar;

	printf("Enter the letter to be encoded: ");
	scanf("%c", &plainChar);

	if (isLowerCase(plainChar)) 
	{
		encodedChar = encode(plainChar);
	}
	else if (isHigherCase(plainChar)) 
	{
		encodedChar = encode(plainChar);
	}
	else 
	{
		encodedChar = plainChar;
	}
	printf("Encoded is: %c\n", encodedChar);

	return EXIT_SUCCESS;
}

int isLowerCase(char letter) 
{
	return (letter >= FIRST_LC_LETTER) && (letter <= LAST_LC_LETTER);
}

int isHigherCase(char letter) 
{
	return (letter >= FIRST_CP_LETTER) && (letter <= LAST_CP_LETTER);
}

void testEncode(void) {
	/*assert(encode('a') == 'b');
	assert(encode('z') == 'a');
	assert(encode('A') == 'B');
	assert(encode('7') == '7');
	assert(encode('Z') == 'A');
	*/
	assert(encode('h') == 'u');
	assert(encode('u') == 'h');
	assert(encode('m') == 'z');
	assert(encode('p') == 'c');
	assert(encode('t') == 'g');
	assert(encode('y') == 'l');
	assert(encode('H') == 'U');
	assert(encode('U') == 'H');
	assert(encode('M') == 'Z');
	assert(encode('P') == 'C');
	assert(encode('T') == 'G');
	assert(encode('Y') == 'L');
	assert(encode('7') == '7');
	

	printf("All tests passed. You are Awsome!\n");
}


char encode(char plainText) 
{
	char cipherText;
	int toBeEncodedLower = isLowerCase(plainText);
	int toBeEncodedHigher = isHigherCase(plainText);

	if (toBeEncodedLower) 
	{
		cipherText = plainText + 13;

		if (cipherText > LAST_LC_LETTER) 
		{
			printf("overflow lower");
			cipherText = (FIRST_LC_LETTER + (cipherText - LAST_LC_LETTER));
		}

	}
	else if (toBeEncodedHigher) 
	{
		cipherText = plainText + 13;

		if (cipherText > LAST_CP_LETTER) 
		{
			printf("overflow higher");
			cipherText = (FIRST_CP_LETTER + (cipherText - LAST_CP_LETTER));
		}

	}
	else 
	{
		cipherText = plainText;
	}

	printf("%c is cipher\n", cipherText);
	return cipherText;
}