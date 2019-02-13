/** mystruct.c
 * @author Ravi Kirschner
*/


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the employee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee* e = (struct Employee*)malloc(sizeof(struct Employee)); //mallocs an employee
	e->birth_year = birth;
	e->start_year = start;
	strcpy(e->name, name); //copies the passed in name into e's name field, just the data
	return e;
}

/**
 * A function to print all the fields of an employee struct to the console
 * @param e the employee to print out
 * @return none
 */
void printEmployee(struct Employee *e) {
	printf("Birth year = %d\n", e->birth_year);
	printf("Starting year = %d\n", e->start_year);
	printf("Name = %s\n", e->name);
}

/**
 * Generates a random employee
 * @param nome
 * @return a random employee struct
 */
struct Employee* makeRandomEmployee() {
	int birth = rand();
	int startyear = rand(); //random birth and start year
	char* name = generateRandomString(); //generates random name
	struct Employee* retPtr = makeEmployee(birth, startyear, name);
	free(name); //frees the name as the documentation says it must be freed manually
	return retPtr;
}

/**
 * Generates a random printable character.
 * @param none
 * @return the random character
 */
char* generateRandomChar() {
	return 'A'+(char)rand()%26;
}

/**
 * Generates a random string from length of 0 to 20. The string pointer must be freed once
 * the user is done with it.
 * @param none
 * @return a random string
 */
char* generateRandomString() {
	int strlength = rand()%20+1; //+1 incase we get a 0
	char* str = (char*)malloc(sizeof(char)*strlength+1); //mallocs with 1 extra for the null terminator
	char* retPtr = str;
	for(int i = 0; i < strlength; i++) {
		*str = generateRandomChar(); //adds a random character to string
		str++;
	}
	*str = '\0'; //null terminates
	return retPtr;
}

/**
 * Generates an array of size count full of random employees. The Employee array must
 * be freed once the user is done with it.
 * @param count the size of the array
 * @return the array filled with random employees.
 */
struct Employee** makeEmployeeArray(int count) {
	struct Employee** array = (struct Employee**)malloc(sizeof(struct Employee)*count);
	struct Employee** retPtr = array;
	while(count > 0) {
		*array = makeRandomEmployee(); //adds a random employee to the array slot
		array++;
		count--;
	}
	return retPtr;
}

/**
 * Prints an entire array of employees to the console.
 * @param e the array of employees to be printed
 * @param size the size of the array e
 * @return none
 */
void printEmployeeArray(struct Employee** e, int size) {
	while(size > 0) {
		printEmployee(*e);
		e++;
		size--;
	}
}

/**
 * Shallow copies an array of employee structs. That is to say, it makes a new array but the
 * pointers inside of it are the same.
 * @param e the old array of Employees
 * @param size the size of the old array
 * @return a new array of Employees with the same data as e but not the same pointers
 */
struct Employee** shallowCopy(struct Employee** e, int size) {
	struct Employee** newArray = (struct Employee**)malloc(sizeof(struct Employee)*size);
	struct Employee** retPtr = newArray;
	for(int i = 0; i < size; i++) {
		*newArray = *e; //sets the pointer at position i of the new array to pointer at pos i of e.
		newArray++;
		e++;
	}
	return retPtr;
}

/**
 * Frees the interior content of an employee array, as well as e itself.
 * @param e the array to free
 * @param size the size of the array
 * @return none
 */
void freeArray(struct Employee** e, int size) {
	struct Employee** originalPointer = e;
	for(int i = 0; i < size; i++) {
		free(*e); //frees the data at *e, so the struct
		e++;
	}
	free(originalPointer); //frees the array pointer itself
}

/**
 * Deep copies the employee e into a new employee, that is to say all the data is the same but all the
 * pointers to the data are different.
 * @param e the employee to deep copy
 * @return a deep copied version of e
 */
struct Employee* copyEmployee(struct Employee* e) {
	struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
	newEmployee->birth_year = e->birth_year;
	newEmployee->start_year = e->start_year;
	strcpy(newEmployee->name, e->name); //copies name data but not the pointer itself
	return newEmployee;
}

/**
 * Deep copies an array of employees into a new array of employees, where all the data is the same
 * but new pointers to all that data.
 * @param e the employee array to deep copy
 * @param size the size of the array
 * @return a deep copied version of e
 */
struct Employee** deepCopy(struct Employee** e, int size) {
	struct Employee** newArray = (struct Employee**)malloc(sizeof(struct Employee)*size);
	struct Employee** retPtr = newArray;
	for(int i = 0; i < size; i++) {
		*newArray = copyEmployee(*e); //sets the employee at position i of new array
		//to a deep copy of the employee at position i of e.
		newArray++;
	}
	return retPtr;
}
