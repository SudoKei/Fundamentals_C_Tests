# Practice 5
Let us have a string containing the list of students (name and code).  
The componensts of list are separated by semicolon followed by one space.  

Example:  
~~~
char students[]="John Smith 25156IVSB; Mary Weaver 253742ABB; James Carpenter 252422TAF; Elizabeth Clerk 251443MV"; 
~~~
Let us have also 3 strings presenting the marks got in examination like:  
~~~
char Mathmatics[]="Mary Weaver 5; John Smith 4; Elizabeth Cleark 4; James Carpenter 2";  
char Physics[]="Mary Weaver 3; John Smith 5; Elizabeth Clerk 2; James Caroenter 2";  
char Chemistry[]="Elizabeth Clerk 4; Mary Weaver 5; John Smith 1; James Carpenter 3";  
~~~

The names in all the 4 strings are the same but the order of components may be different.  
Turn attention that there is no semicolon after the last component.  

Write a function with prototype:  
~~~
STUDENT *Exam(char *pStudents, char *pMathmatics, char *pPhysics, char *pChemistry);  
~~~

where  
~~~
typedef struct student{  
  char *pName, *pCode;  
  int mMathmatics, mPhysics, mChemistry;  
  double Average }STUDENT;  
~~~  
Here mMathmatics, etc, are marks extracted from input strings.
The function must create struct student presenting the student who has the highest average and return a pointer of the struct.
