/** mystruct.h
 * @author Ravi Kirschner
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
struct Employee* makeRandomEmployee();
struct Employee* copyEmployee(struct Employee* e);
struct Employee** makeEmployeeArray(int count);
struct Employee** shallowCopy(struct Employee** e, int size);
struct Employee** deepCopy(struct Employee** e, int size);
char* generateRandomChar();
char* generateRandomString();
void printEmployee(struct Employee *e);
void printEmployeeArray(struct Employee** e, int size);
void freeArray(struct Employee** e, int size);
