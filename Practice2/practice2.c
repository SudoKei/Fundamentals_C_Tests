#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct item{
char *pName;
int quantity, write_off;
}ITEM;

ITEM *Exam(char *pInput,  char *pItemName);

int main(){

  char Input[]="[ Name: Mackerel   Quantity: 1000   Expires: 10-2018   ]   [ Quantity: 500   Name: Sardine   Expires: 12-2017   ]   [ Expires: 1-2020   Quantity: 10000    Name: Tuna   ]";

  char ItemName[]="Sardine";
  
  ITEM *result;
  result=Exam(Input,ItemName);

  printf("%s\n%d\n%d\n",result->pName,
	 result->quantity,
	 result->write_off); 

  free(result->pName);
  free(result);
  return 0;
  
}

ITEM *Exam(char *pInput,  char *pItemName){
  
  char *find;
  find=strstr(pInput,pItemName);

  if(find == NULL){
    printf("No existance\n");
    exit(1);
  }

  char *start;
  int i=0;
  while(*(find+i)!='\0'){
    if(*(find+i) == '['){
      start = find+i;
      break;
    }
    i--;
  }

  ITEM *Item;
  Item = (ITEM*)malloc(sizeof(ITEM));

  //pName
  Item->pName = (char*)malloc(sizeof(char)*strlen(pItemName));
  strcpy(Item->pName,pItemName);
 
  //Quantity
  find=strstr(start,"Quantity: ");
  Item->quantity=atoi(find+strlen("Quantity: "));
  
  //Expires
  int month=0;
  int year=0;

  find=strstr(start,"Expires: ");
  month = atoi(find+strlen("Expires: "));
 
  find = strstr(start,"-");
  year = atoi(find+1);
  
  if(year<2019 ||(month<=1 && year==2019)){
    Item->write_off = 1;
  }else{
    Item->write_off = 0;
  }
  
  return Item;
}
