# Practice 3  
Write a function with prototype:  
~~~
ITEM *Exam(char *pInput,  int *pnItems);  
~~~

Here:  
~~~
typedef struct item {  
char *pName;  
int Quantity, Price, Total;  
} ITEM;  
~~~
   
and the input string consists of segments “item_name, quantity, price;”  
for example:  
~~~
Shirt, 100, 15;   Jacket, 250, 120;  
~~~
 
The number of segments is not restricted.  
There is only one space between the components of segments (i.e. after comma).  
But there may be any numbers (except 0 pieces) of spaces between segments (i.e. after semicolon)  
The item name stats with Uppercase letter, and do not contain spaces.  
The semicolon is after each segment.  
   
The function must create an array of ITEM structs and, extracting the needed information from the input string, fill its fields for each item.  
The function returns the pointer to the created array.  
The number of created items must be stored into field pointed by parameter pnItems.  
You may suppose that the input string is absolutely correct, i.e. its checking is not needed.  
   
To get Total, multiply Quantity and Price(Total = Quantity*Price)  
Write also main to test the code.  
