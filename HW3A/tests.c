/*
 * tests.c
 *
 *  Created on: Jan 24, 2019
 *      Author: student
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystring.h"

bool tests(void)
{
	bool ok = false;
	bool ok1 = testMystrlen1();

	if (ok1) {
		puts("mystrlen1() passed.");
	}

	bool ok2 = testMystrlen2();
	if (ok2) {
		puts("mystrlen2() passed.");
	}

	bool ok3 = testMystrdup();
	if (ok3) {
		puts("mystrdup() passed.");
	}

	bool ok8 = testMystrndup();
	if (ok8) {
		puts("mystrndup() passsed.");
	}

	bool ok4 = testMystrncpy();
	if (ok4) {
		puts("mystrncpy() passed.");
	}

	bool ok5 = testMystrcpy();
	if (ok5) {
		puts("mystrcpy() passed.");
	}

	bool ok6 = testMystrncat();
	if (ok6) {
		puts("mystrncat() passed.");
	}

	bool ok7 = testMystrcat();
	if(ok7) {
		puts("mystrcat() passed");
	}

	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8; // Did all tests pass?
	return ok;
}

/** Tests the mystrlen1() function by comparing it to how the standard strlen() works..
 * @return true if it passes all tests.
 */
bool testMystrlen1(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	char* s1 = "Some sample string."; // String we will take the length of.
	size_t l1a = strlen(s1); // Get the lengths with the two functions.
	size_t l1b = mystrlen1(s1);
	if (l1a == l1b) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t l2a = strlen(s2); // Get the lengths with the two functions.
	size_t l2b = mystrlen1(s2);
	if (l2a == l2b) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
}


/** Tests the mystrlen2() function by comparing it to how the standard strlen() works..
 * @return true if it passes all tests.
 */
bool testMystrlen2(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	char* s1 = "Some sample string."; // String we will take the length of.
	size_t l1a = strlen(s1); // Get the lengths with the two functions.
	size_t l1b = mystrlen2(s1);
	if (l1a == l1b) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t l2a = strlen(s2); // Get the lengths with the two functions.
	size_t l2b = mystrlen2(s2);
	if (l2a == l2b) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
	return ok;
}

/** Test mystrdup() function by comparing it to the standard strdup().
 * @return true if it passes all tests.
 */
bool testMystrdup() {
	bool ok1 = false;

	char s1[] = "Some sample string."; // String we will duplicate.
	char* s2 = strdup(s1); // Copy it using standard function
	char* s3 = mystrdup(s1); // Copy it using my function

	if (strcmp(s2, s3) == 0) { // Same result!
		ok1 = true;
	}

	char* s4 = "Some other string."; // Another string for testing
	printf("Address of a local variable ok1, on stack:   %p\n", &ok1);
	printf("Address of original string, on stack:        %p\n", s1);
	printf("Address of first duplicate string, on heap:  %p\n", s2);
	printf("Address of second duplicate string, on heap: %p\n", s3);
	printf("Address of other string, on heap?:           %p\n", s4);

	bool ok = ok1;
	return ok;
}

/**
 * Test mystrndup() function.
 * @return true if pass, false if fail.
 */
bool testMystrndup() {
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	char str[] = "String1";
	//n is exactly equal to the size of str
	char* stddup1 = strndup(str,7);
	char* mydup1 = mystrndup(str,7);
	printf("In testMystrndup(), stddup1 is %s\n", stddup1);
	ok1 = !strcmp(stddup1, mydup1);

	//n is less than the size of str
	char* stddup2 = strndup(str, 3);
	char* mydup2 = mystrndup(str, 3);
	printf("In testMystrndup(), stddup2 is %s\n", stddup2);
	ok2 = !strcmp(stddup2, mydup2);

	//n is greater than the size of str
	char* stddup3 = strndup(str, 15);
	char* mydup3 = mystrndup(str, 15);
	printf("In testMystrndup(), stddup3 is %s\n", stddup3);
	ok3 = !strcmp(stddup3, mydup3);
	return ok1 && ok2 && ok3;;
}

/*
 * Test mystrcpy() function.
 * @return true if pass, false if fail.
 */
bool testMystrcpy() {
	bool ok1 = false;
	bool ok2 = false;

	char s1[] = "Some sample string."; // String we will copy.
	char s2[30]; // Empty string we will copy into

	char* s3 = mystrcpy(s2, s1); // Copy the string
	if (strcmp(s1, s2) == 0) { // Does original equal copy?
		ok1 = true; // Yes!
	}

	if (s3 == s2) { // Is the return value correct?
		ok2 = true; // Yes!
	}

	bool ok = ok1 && ok2;
	return ok;
}

/*
 * Test mystrncpy() function.
 * @return true if pass, false if fail.
 */
bool testMystrncpy() {
	//n is exactly equal to the size of str
	bool ok1 = false;
	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it.
	char* s3a = strncpy(s1a, s2a, 6); // The result

	printf("In testMystrncpy(): s3a = /%s/\n", s3a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it.
	char* s3b = mystrncpy(s1b, s2b, 6); // The result

	if (strcmp(s3a, s3b) == 0) {
		ok1 = true;
	}

	//n is greater than the size of str
	bool ok2 = false;
	char s1c[] = "012345678901234567890123456789"; // A long string
	char s2c[] = "ABCDEF"; // A short string we will copy into it.
	char* s3c = strncpy(s1c, s2c, 15); // The result

	printf("In testMystrncpy(): s3c = /%s/\n", s3c);

	char s1d[] = "012345678901234567890123456789"; // A long string
	char s2d[] = "ABCDEF"; // A short string we will copy into it.
	char* s3d = mystrncpy(s1d, s2d, 15); // The result

	ok2 = !strcmp(s3c,s3d);

	//n is less than the size of str
	bool ok3 = false;
	char s1e[] = "012345678901234567890123456789"; // A long string
	char s2e[] = "ABCDEF"; // A short string we will copy into it.
	char* s3e = strncpy(s1e, s2e, 3); // The result

	printf("In testMystrncpy(): s3e = /%s/\n", s3e);

	char s1f[] = "012345678901234567890123456789"; // A long string
	char s2f[] = "ABCDEF"; // A short string we will copy into it.
	char* s3f = mystrncpy(s1f, s2f, 3); // The result

	ok3 = !strcmp(s3e,s3f);

	return ok1 && ok2 && ok3;
}

/*
 * Test mystrncat() function.
 * @return true if pass, false if fail.
 */
bool testMystrncat() {
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	bool ok4 = false;
	bool ok5 = false;
	bool ok6 = false;
	bool ok7 = false;
	bool ok8 = false;

	//n is exactly equal to the size of str.
	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it twice.
	char* s3a = strcpy(s1a, s2a);
	char* s4a =	strncat(s1a, s2a, 6); // The result

	printf("In testMystrncat(): s1a = /%s/\n", s1a);
	printf("In testMystrncat(): s4a = /%s/\n", s4a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it twice.
	char* s3b = strcpy(s1b, s2b);
	char* s4b = mystrncat(s1b, s2b, 6); // The result

	if (strcmp(s1a, s1b) == 0) {
		ok1 = true;
	}

	if (strcmp(s4a, s4b) == 0) {
		ok2 = true;
	}

	//n is less than the size of str.
	char longs1[] = "AAAAAAAAAAAAAAAAAA"; //long string
	char tocat1[] = "catme"; //smaller string to copy then cat
	mystrcpy(longs1, tocat1);
	char* newstring1 = strncat(longs1, tocat1, 3); //concat the first 3 letters of tocat1, so "cat"

	printf("In testMystrncat: newstring1 = %s\n", newstring1);

	char longs2[] = "AAAAAAAAAAAAAAAAAA";
	char tocat2[] = "catme";
	mystrcpy(longs2, tocat2);
	char* newstring2 = mystrncat(longs2, tocat2, 3);

	ok3 = !strcmp(longs1, longs2); //should be 0, so that means false. if !0 then its true.
	ok4 = !strcmp(newstring1, newstring2);
	ok5 = !strcmp(newstring2, "catmecat"); //just to make sure it is what we expected.

	//n is greater than the size of str.
	char longs3[] = "AAAAAAAAAAAAAAAAAA"; //long string
	char tocat3[] = "catme"; //smaller string to copy then cat
	mystrcpy(longs3, tocat3);
	char* newstring3 = strncat(longs3, tocat3, 9); //going to concat entirety of it, but n > length.

	printf("In testMystrncat: newstring3 = %s\n", newstring3);

	char longs4[] = "AAAAAAAAAAAAAAAAAA";
	char tocat4[] = "catme";
	mystrcpy(longs4, tocat4);
	char* newstring4 = mystrncat(longs4, tocat4, 9);

	ok6 = !strcmp(longs3, longs4);
	ok7 = !strcmp(newstring3, newstring4);
	ok8 = !strcmp(newstring4, "catmecatme"); //just to make sure it is what we expected.

	return ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8;
}

/**
 * Test mystrcat() function.
 * @return true if pass, false if fail.
 */
bool testMystrcat() {
	char s1a[] = "012345678901234567890123456789\0\0\0\0\0\0";
	char s2a[] = "ABCDEF";
	printf("In testMystrcat: s1a is %s\n", s1a);
	printf("In testMystrcat: s2a is %s\n", s2a);
	char* s3a = strcat(s1a,s2a);
	printf("Result in testMystrcat for s3a: %s\n", s3a);

	char s1b[] = "012345678901234567890123456789\0\0\0\0\0\0";
	char s2b[] = "ABCDEF";
	printf("In testMystrcat: s1b is %s\n", s1b);
	printf("In testMystrcat: s2b is %s\n", s2b);
	char* s3b = mystrcat(s1b,s2b);
	printf("Result in testMystrcat for s3b: %s\n", s3b);

	bool ok1 = strcmp(s3a,s3b) == 0;

	char fulls1[] = "ToCat";
	char others1[10] = "when";
	char* originalcat = strcat(others1, fulls1);

	char fulls2[] = "ToCat";
	char others2[10] = "when";
	char* newcat = mystrcat(others2, fulls2);

	bool ok2 = strcmp(originalcat, newcat) == 0;

	return ok1 && ok2;
}
