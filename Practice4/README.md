# Practice 3  
Write a function with prototype:  
~~~
EMPLOYEE *Exam(char *pInput);  
~~~
 
Here:  
~~~
typedef struct employee {  
char *pFirstName, *pMiddleName, *pLastName;  
int Brutto, TaxCoefficient, Netto;  
} EMPLOYEE;  
~~~
 
and the input string format is “first_name middle_name last_name brutto_income;”  
for example:  
~~~
John James Smith 15000;
~~~
The middle name is optional, i.e. the input string may be also like:  
~~~
John Smith 15000;  
~~~
The brutto income is an integer. There is only one space between components.  
 
The tax coefficient is 25% if the brutto income exceeds 10000,  
20% if the brutto income is between 7500 and 10000,  
15% if the brutto income is between 5000 and 7500,  
0% if the brutto income is less that 5000.  
 
The function must allocate memory for output struct and, extracting the needed information from the input string, fill its fields.  
If middle name is not present, the pointer to it must be zero.  
The function returns the pointer to the created struct.  
 
You may suppose that the input string is absolutely correct, i.e. its checking is not needed.  
 
Write also main to test the code.  
