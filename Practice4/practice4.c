#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct employee{
char *pFirstName, *pMiddleName, *pLastName;
int Brutto, TaxCoefficient, Netto;
}EMPLOYEE;

EMPLOYEE *Exam(char *pInput);
void BruttoCalc(EMPLOYEE *pEmployee);

int main(){
  //char Input[]="John James Smith 15000;";
  char Input[]="John Smith 5000;";
  EMPLOYEE *result;

  result = Exam(Input);
  printf("FirstName:%s\nMiddleName:%s\nLastName:%s\n",result->pFirstName,
	 result->pMiddleName,
	 result->pLastName);
  printf("Brutto:%d\nTaxCoefficient:%d\nNetto:%d\n",result->Brutto,
	 result->TaxCoefficient,
	 result->Netto);

  return 0;
}

EMPLOYEE *Exam(char *pInput){
  EMPLOYEE *Employee = (EMPLOYEE*)malloc(sizeof(EMPLOYEE));

  int spaces=0;
  int i=0;
  while(pInput[i]!='\0'){
    if(pInput[i] == ' ')spaces++;
    i++;
  }
  int isMiddle=0;
  if(spaces == 3)isMiddle = 1;
  
  char *flag;
  //set the flag at the beginning of the input
  flag = pInput;
  i=0;
  int process=0;
  while(pInput[i]!='\0'){
    if(pInput[i] == ' '){
      pInput[i] = '\0';
      
      if(process == 0){
	//First Name
	Employee->pFirstName = (char*)malloc(sizeof(char)*strlen(flag)+1);
	strcpy(Employee->pFirstName,flag);
      }
      if(process == 1 && isMiddle == 1){
	//Middle Name if it exsits
	Employee->pMiddleName = (char*)malloc(sizeof(char)*strlen(flag)+1);
	strcpy(Employee->pMiddleName,flag);
      }
      if(process == 1 && isMiddle == 0){
	//Middle Name if it does not exist
	Employee->pMiddleName = NULL;
      }
      if((process == 2 && isMiddle == 1)||(process == 1 && isMiddle == 0)){
	//Last Name
	Employee->pLastName = (char*)malloc(sizeof(char)*strlen(flag)+1);
	strcpy(Employee->pLastName,flag);

	//Brutto
	flag = pInput+i+1;
	Employee->Brutto = atoi(flag);
      }
      
      pInput[i] = ' ';
      flag = pInput+i+1;
      process++;
    }
    i++;
  }
  BruttoCalc(Employee);

  return Employee;
}

void BruttoCalc(EMPLOYEE *pEmployee){
  //10000<= Brutto
  if(pEmployee->Brutto >= 10000){
    pEmployee->TaxCoefficient = 25;
    pEmployee->Netto = pEmployee->Brutto*75/100;
  }
  //7500<= Brutto < 10000
  if(pEmployee->Brutto >= 7500 && pEmployee->Brutto < 10000){
    pEmployee->TaxCoefficient = 20;
    pEmployee->Netto = pEmployee->Brutto*80/100;
  }
  //5000<= Brutto < 7500
  if(pEmployee->Brutto >= 5000 && pEmployee->Brutto < 7500){
    pEmployee->TaxCoefficient = 15;
    pEmployee->Netto = pEmployee->Brutto*85/100;
  }
  //Brutto < 5000
  if(pEmployee->Brutto < 5000){
    pEmployee->TaxCoefficient = 0;
    pEmployee->Netto = pEmployee->Brutto;
  }
}

