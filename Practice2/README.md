# Practice 2   
Write a function with prototype:  
~~~
*Exam(char *pInput,  char *pItemName);
~~~
 
Here:  
~~~
typedef struct item{  
char *pName;  
int quantity, write_off; //write_off: 0, if not expired yet, 1 if expired  
} ITEM; 
~~~
 
and the input string consists of segments enclosed into brackets.  
 
The segments contain 3 components: "[Name: string  Quantity: integer  Expires: integer - integer]"   
The order of components may be any.  
Example:  
~~~
[ Name: Mackerel   Quantity: 1000   Expires: 10–2018   ]   [ Quantity: 500   Name: Sardine   Expires: 12–2017   ]   [ Expires: 1–2020   Quantity: 10000    Name: Tuna   ]
~~~
 
The number of spaces in components and between segments is any except zero (as many as you want) but after colon (:) only one.  
There are also spaces before ] and after [ .
The item name does not contain spaces.
 
The function must create a struct ITEM for item whos name is specified by the pointer pItemName and, extracting the needed information from the input string, fill its fields. The function returns the pointer to the created struct.
 
You may suppose that the input string is absolutely correct, i.e. its checking is not needed.
However, the item with the specified name may be not present in the input string. In that case the function must return 0.
To know whether the item must be write off, compare the date of expire with January 2019.
 
Write also main to test the code.
