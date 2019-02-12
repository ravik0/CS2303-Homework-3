/*
 * mystring.c
 *
 *  Created on: Jan 24, 2019
 *      Author: student
 */
#include <stdlib.h>
#include "mystring.h"

/**
 * Calculate the length of the string,
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen1(const char* s)
{
	size_t n = 0;

	// Step through the array, counting up until we find the null terminator
	while (s[n] != '\0') {
		n++;
	}

	return n;
}
/**
 * Calculate the length of the string
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen2(const char* s)
{
	size_t n = 0;

	// Keep incrementing the pointer until we find it is pointing to the null terminator
	while (*s != '\0') {
		n++;
		s++;
	}

	/* Note: This could have been written as:
	 while (*(s++)) n++;
	 */

	return n;
}

/** Duplicates a character string into a freshly-allocated block of memory.
 * @param s The string to duplicate.
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrdup(char* s) {
	size_t length = strlen(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		strcpy(newstr, s);
	}
	return newstr;
}

/**
 * Duplicates the first n characters of a string into a newly allocated block of memory.
 * If n is less than the size of src, the first n characters of src will be duplicated and
 * a null terminator will be added.
 * @param s the string to duplicate
 * @param n the number of characters to duplicate
 * @return a pointer to the newly duplicated string
 */
char* mystrndup(char* s, size_t n) {
	char* newstr = (char*) malloc(n+1);
	char* retPtr = newstr;
	if(newstr != NULL) {
		for(int i = 0; i < n; i++) {
			*newstr = *s;
			newstr++;
			s++;
		}
		*newstr = '\0';
	}
	return retPtr;
}

/**
 * Copies a string src into the address dest. Overwrites anything at dest. Src and dest should have
 * the same size, that is if src is 10 characters, dest should be as well.
 * @param char* the destination to copy into
 * @param char* the source location to copy from
 * @return the start of the newly copied to string, or just dest
 */
char* mystrcpy(char* dest, char* src) {
	char* initialDestPos = dest;
	while(*dest++ = *src++);
	*dest = '\0';
	dest = initialDestPos;
	return initialDestPos;
}

/**
 * Copies the first n characters of src to the string pointed to by dest
 * As this function copies AT MOST n bytes from src, the function does not
 * null terminate if n < src. Else if n is greater than strlen(src),
 * the function will write null terminators until n bytes of data are
 * written into dest.
 * @param dest the destination to copy into
 * @param src the src to copy from
 * @param n the amount of bytes to copy
 * @return pointer to dest
 */
char* mystrncpy(char* dest, char* src, size_t n) {
	char* retPtr = dest;
	for(int i = 0; i < n; i++) {
		if(*src != '\0') {
			*dest = *src;
			dest++;
			src++;
		}
		else if (*src == '\0') {
			*dest = '\0';
			dest++;
		}
	}
	return retPtr;
}
/**
 * Appends the first n characters of src to the string pointed to by dest, plus a null terminator.
 * If n is greater than the length of *src, then it just appends over the entirety of src.
 * If n is equal to the length of src, it simply appends over the entirety of src.
 * If n is less than the length of src, only the first n characters of src (and a null terminator)
 * will be appended to dest.
 * @param dest the destination to concatenate onto
 * @param src the source to concatenate from
 * @param n the amount of characters to concatenate over from src
 * @return pointer to dest
 */
char* mystrncat(char* dest, char* src, size_t n) {
	int srcLen = mystrlen2(src);
	char* retValue;
	if(n >= srcLen) {
		retValue = mystrcat(dest, src);
	}
	else {
		retValue = dest;
		dest+=mystrlen2(dest);
		do {
			*dest = *src;
			dest++;
			src++;
			n--;
		} while (n > 0);
		*dest = '\0';
	}
	return retValue;
}

/**
 * Concatenates a copy of the string pointed to by src onto the end of the
 * string pointed to by dest. Overwrites the null character at the end of dest,
 * and adds a null terminator at the end of the new string. Will concatenate even if
 * there is not enough space in dest.
 * @param dest the destination to concatenate onto
 * @param src the string to concatenate onto dest.
 * @return a pointer to dest
 */
char* mystrcat(char* dest, char* src) {
	int endOfDest = mystrlen2(dest);
	char* retValue = dest;
	dest+=endOfDest;
	mystrcpy(dest,src);
	return retValue;
}
