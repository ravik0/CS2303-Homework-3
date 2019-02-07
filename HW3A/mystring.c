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
 * Copies a string src into the address dest. Overwrites anything at dest. Src and dest should have
 * the same size, that is if src is 10 characters, dest should be as well.
 * @param char* the destination to copy into
 * @param char* the source location to copy from
 * @return the start of the newly copied to string, or just dest
 */
char* mystrcpy(char* dest, char* src) {
	char* initialDestPos = dest;
	while(*dest++ = *src++);
	dest = initialDestPos;
	return initialDestPos;
}

/** Must fill in
 *
 */
char* mystrncpy(char* dest, char* src, size_t n) {
	// Must fill in
	return dest;
}
/** Must fill in
 *
 */
char* mystrncat(char* dest, char* src, size_t n) {
	// Must fill in
	return dest;
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
