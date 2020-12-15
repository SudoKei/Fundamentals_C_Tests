#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct item{
char *pName;
int Quantity, Price, Total;
}ITEM;

ITEM *Exam(char *pInput,int *pnItems);

int main(){
  char Input[]="Shirt, 100, 15;   Jacket, 250, 120;     Coat, 10, 20;   ";
  int nItems = 3;
  ITEM *pItem;

  pItem = Exam(Input,&nItems);

  int i;
  for(i=0;i<nItems;i++){
    printf("Item No.%d\nItem Name:%s\nQuantity:%d\nPrice:%d\nTotal:%d\n",
	   i+1,
	   pItem[i].pName,
	   pItem[i].Quantity,
	   pItem[i].Price,
	   pItem[i].Total);
    free(pItem[i].pName);
  }
  free(pItem);
}

ITEM *Exam(char *pInput,int *pnItems){
  ITEM *Items;
  Items = (ITEM*)malloc(*pnItems*sizeof(ITEM));
  
  char *start_flag;
  char *end_flag;

  //set flag at the beginning of the input string
  start_flag=pInput;
  
  int i=0;
  for(i=0;i<*pnItems;i++){
    //pName
    end_flag = strstr(start_flag,",");
    *(end_flag)='\0';
    Items[i].pName = (char*)malloc(sizeof(char)*strlen(start_flag)+1);
    strcpy(Items[i].pName,start_flag);
    *(end_flag)=',';

    //Quantity
    start_flag=end_flag+1;
    end_flag = strchr(start_flag,',');
    Items[i].Quantity = atoi(start_flag);

    //Price
    start_flag=end_flag+1;
    end_flag = strchr(start_flag,';');
    Items[i].Price = atoi(start_flag);

    //Total
    Items[i].Total = Items[i].Quantity * Items[i].Price;
    
    int j=1;
    while(*(end_flag+j) == ' '){
      j++;
    }
    start_flag = end_flag+j;
    
  }
  return Items;
}
