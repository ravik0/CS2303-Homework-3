/*
 * tests.h
 *
 *  Created on: Feb 4, 2019
 *      Author: Ravi Kirschner
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <stdbool.h>
#include "production.h"

// Function prototypes:
bool tests(void);
bool testPrintEmployee(void);
bool testMakeEmployee();
bool testGenerateRandomChar();
bool testGenerateRandomString();
bool testMakeRandomEmployee();
bool testPrintEmployeeArray();
bool testMakeEmployeeArray();
bool testShallowCopy();
bool testFreeArray();
bool testCopyEmployee();
bool testDeepCopy();

#endif /* TESTS_H_ */
