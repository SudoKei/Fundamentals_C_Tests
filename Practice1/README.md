# Practice 1
Write a function with prototype:  
~~~
STUDENT *Exam(char *pInput,  char *pStudentName);
~~~

Here:  
~~~
typedef struct student{    
char *pName;  
int nMarks, *pMarks; //number of marks and pointer to array of marks   
double AverageMark;  
} STUDENT;  
~~~

and the input string consists of segments "name, mark1, mark2, ... ;"   
for example:  
~~~
John Smith, 4, 2, 5, 3;   James Farmhand, 4;
~~~

The number of segments is not restricted and the number of marks of a student may be any (but nor 0 pieces). The marks are from interval 0...5.   
There is only one space between the components of segments (i.e. after comma and colon)  
But there may be any number (except 0 pieces) of spaces between segments (i.e. after semicolon)  
The semicolon is after each segment.  

The function must create a struct STUDENT for student whos name in specified by the pointer pStudentName and, extracting the needed information from the input string, fill its fields. The function returns the pointer to the created struct.  

You may suppose that the input string is absolutely correct, i.e. its checking is not needed.  
However, the student with the specified name may be not present in the input string.  
In that case the function must return 0.  

Write also main to test the code  
