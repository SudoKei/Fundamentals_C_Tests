# Mock Exam  
Let us have  
~~~
typedef struct {  
int day;   
char month[4];  
int year;  
} DATE;  
 
typedef struct {  
const char *pFirstName, *pLastName, *pNationality;   
DATE Birthdate;  
} STUDENT;  
~~~ 
Write a function with prototype:  
~~~
int Exam(STUDENT *pStudents, int nStudents, const char *pPattern);  
~~~
where pStudents points to an array with length nStudents, for example: 
~~~
STUDENT students[] = {  {"John”,”Smith”,”Britain”, {1, “Feb”, 2000}},  {"Mary”,”Weaver”,”USA”, {2, “Mar”, 2001}},  {"James”,”Carpenter”,”Canada”, {11, “Oct”, 2002}},  {"Elizabeth”,”Clerk”,”Ireland”, {21, “Dec”, 2001}}  };  
~~~
 
The pattern is a string formatted as  “<last-name>, <first-name> born<day> <month-in-English> <year> from<country>”   
 
Example:  
~~~
const char *ptoSearch = “Carpenter, James born 11 October 2002 from Canada”;  
printf(“%s\n”, Exam(students, 4));  
~~~
The output value is 1 if the student specified by pattern string is in the input array, and 0 if not.  
For example, if the call is:  
~~~
printf(“%d\n”, Exam(students, 4, ptoSearch)); //prints 1  
~~~
 
The input pointers may not be zero and may not point to empty strings. Number of students may not be zero.  
If those conditions are not satisfied, the function must return zero.  
However, if those conditions are satisfied, we may be sure that the input data is 100% correct.  
The nationality is always presented by just one word.  
 
Write also main to test the code and print the results.  
