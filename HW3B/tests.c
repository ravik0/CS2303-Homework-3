/*
 * tests.c
 *
 *  Created on: Feb 4, 2019
 *      Author: Ravi Kirschner
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "mystruct.h"

bool tests(void)
{
	bool ok = false;

	bool ok1 = testPrintEmployee();
	if (ok1) {
		puts("printEmployee() passed.");
	}

	bool ok2 = testMakeEmployee();
	if (ok2) {
		puts("makeEmployee() passed.");
	}

	bool ok3 = testGenerateRandomChar();
	if (ok3) {
		puts("generateRandomChar() passed");
	}

	bool ok4 = testGenerateRandomString();
	if (ok4) {
		puts("generateRandomString() passed");
	}

	bool ok5 = testMakeRandomEmployee();
	if (ok5) {
		puts("makeRandomEmployee() passed");
	}

	bool ok6 = testPrintEmployeeArray();
	if (ok6) {
		puts("printEmployeeArray() passed");
	}

	bool ok7 = testMakeEmployeeArray();
	if (ok7) {
		puts("makeEmployeeArray() passed");
	}

	bool ok8 = testShallowCopy();
	if (ok8) {
		puts("shallowCopy() passed");
	}

	bool ok9 = testFreeArray();
	if (ok9) {
		puts("freeArray() passed");
	}

	bool ok10 = testCopyEmployee();
	if (ok10) {
		puts("copyEmployee() passed");
	}

	bool ok11 = testDeepCopy();
	if(ok11) {
		puts("deepCopy() passed");
	}
	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9; // Did all tests pass?
	return ok;
}

/**
 * Test the printEmployee() function by creating a known struct and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */

bool testPrintEmployee() {
	puts("In testPrintEmployee():");
	struct Employee e; // Variable to hold employee
	e.birth_year = 1952; // Put data into numeric fields
	e.start_year = 1999;
	// Copy into string field. Be sure not to overflow it.
	strncpy(e.name, "Mike Ciaraldi", MAX_NAME);
	e.name[MAX_NAME] = '\0'; // Be sure string is terminated.

	printEmployee(&e);
	return true;
}


/** Test the make Employee() function by making an employee with known data and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testMakeEmployee() {
	puts("In testMakeEmployee():");
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(e);
	free(e);

	return true;
}

/**
 * Tests the generateRandomChar() function by making and printing a character.
 * @return true. The only way to tell if it succeeds is to look at the output
 */
bool testGenerateRandomChar() {
	char* print = generateRandomChar();
	printf("In testGenerateRandomChar(): %c\n", print);
	return true;
}

/**
 * Tests the generateRandomString() function by making and printing a string.
 * @return true. The only way to tell if it succeeds is to look at the output
 */
bool testGenerateRandomString() {
	char* str = generateRandomString();
	printf("In testGenerateRandomString(): %s\n", str);
	free(str);
	return true;
}

/**
 * Tests the makeRandomEmployee() function by generating and printing that employee.
 * @return true. The only way to tell if it succeeds is to look at the output
 */
bool testMakeRandomEmployee() {
	struct Employee* random = makeRandomEmployee();
	puts("In testMakeRandomEmployee():");
	printEmployee(random);
	free(random);
	return true;
}

/**
 * Tests the printEmployeeArray() function by generating an array of employees and printing it
 * @return true. The only way to tell if it succeeds is to look at the output
 */
bool testPrintEmployeeArray() {
	puts("In testPrintEmployeeArray():");
	struct Employee** array = (struct Employee**)malloc(sizeof(struct Employee)*2);
	array[0] = makeEmployee(2000, 2001, "Mark");
	array[1] = makeEmployee(1992, 3001, "Philip J. Fry");
	printEmployeeArray(array, 2);
	freeArray(array, 2);
	return true;
}

/**
 * Tests the makeEmployeeArray() function by calling it and printing the results.
 * @return true. The only way to tell if it succeeds is to look at the output
 */
bool testMakeEmployeeArray() {
	puts("In testMakeEmployeeArray():");
	struct Employee** array = makeEmployeeArray(5);
	printEmployeeArray(array, 5);
	freeArray(array, 5);
	return true;
}

/**
 * Tests the shallowCopy() function by making an array and shallow copying it.
 * To make sure it is okay, we check if the pointers to the arrays themselves are not the same,
 * but we check to see if the pointers within the array are the same.
 * @return true if succeed, false if fair
 */
bool testShallowCopy() {
	puts("In testShallowCopy():");
	bool ok = false;
	struct Employee** arr1 = makeEmployeeArray(4);
	struct Employee** shallow = shallowCopy(arr1, 4);
	for(int i = 0; i < 4; i++) {
		ok = arr1[i] == shallow[i]; //makes sure the pointers are the same
	}
	if(ok) ok = (arr1 != shallow);
	//if the pointers were the same, makes sure array pointers themselves aren't
	freeArray(arr1,4);
	free(shallow); //shallow is already freed as it just a shallow copy, so no freeArray here.
	return ok;
}

/**
 * Tests the freeArray() function by making an array and freeing it
 * @return true. As long as the function doesn't crash the program, it passes.
 */
bool testFreeArray() {
	puts("In testFreeArray():");
	struct Employee** array = makeEmployeeArray(25);
	freeArray(array, 25);
	return true;
}

/**
 * Tests the copyEmployee() function by creating an employee, copying it, and checking pointers
 * @return true if pass, false if fail.
 */
bool testCopyEmployee() {
	puts("In testCopyEmployee():");
	bool ok = false;
	struct Employee* e1 = makeRandomEmployee();
	struct Employee* e2 = copyEmployee(e1);
	ok = &e1->birth_year != &e2->birth_year && e1->birth_year == e2->birth_year;
	printf("e1 birth /%p/, e2 birth /%p/\n", &e1->birth_year, &e2->birth_year);
	ok = &e1->start_year != &e2->start_year && e1->start_year == e2->start_year;
	printf("e1 start /%p/, e2 start /%p/\n", &e1->start_year, &e2->start_year);
	ok = &e1->name != &e2->name && e1->name == e2->name;
	printf("e1 name /%p/, e2 name /%p/\n", &e1->name, &e2->name);
	//checks to make sure all the addresses are different but data is same
	free(e1);
	free(e2);
	return ok;
}

/**
 * Tests the deepCopy() function by creating an array, deep copying it, and checking pointers
 * @return true if pass, false if fail
 */
bool testDeepCopy() {
	puts("In testDeepCopy():");
	bool ok = false;
	struct Employee** arr1 = makeEmployeeArray(5);
	struct Employee** deep = deepCopy(arr1, 5);
	for(int i = 0; i < 5; i++) {
		printf("NEXT EMPLOYEE\n");
		ok = arr1[i] != deep[i]; //check if the pointers are different
		printf("arr1 employee pointer /%p/, deep employee pointer /%p/\n", *arr1, *deep);
		ok = &((struct Employee*)arr1[i])->name != &((struct Employee*)deep[i])->name;
		//make sure pointers are different
		printf("arr1 employee name ptr /%p/, deep employee name ptr /%p/\n", &((struct Employee*)arr1[i])->name,
				&((struct Employee*)deep[i])->name);
		printf("arr1 employee name /%s/, deep employee name /%s/\n", ((struct Employee*)arr1[i])->name,
				((struct Employee*)arr1[i])->name);
	}
	freeArray(arr1, 5);
	freeArray(deep, 5);
	return ok;
}
