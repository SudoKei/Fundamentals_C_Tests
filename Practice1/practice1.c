#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student{
char *pName;
int nMarks, *pMarks; //number of marks and pointer to array of marks
double AverageMark;
}STUDENT;

STUDENT *Exam(char *pInput,  char *pStudentName);

int main(){
  char Input[]="James Farmhand,   4;   John Smith, 4,  2, 5,   3; Keisuke Konno, 3;";
  char StudentName[]="John Smith";
  STUDENT* pStudent;
  
  if(Exam(Input,StudentName)==0){
    printf("No Data\n");
    exit(1);
  }else{
    pStudent = Exam(Input,StudentName);
    printf("Name:%s\nAverage:%f\n",pStudent->pName,pStudent->AverageMark);
  }

  return 0;
}

STUDENT *Exam(char *pInput,  char *pStudentName){
  char *pfound;
  STUDENT *Student = (STUDENT*)malloc(sizeof(STUDENT));
  int size_t = strlen(pStudentName);

  if(strstr(pInput,pStudentName)!=NULL){
    
    //pName
    Student->pName = (char*)malloc(sizeof(char)*size_t+1);
    strcpy(Student->pName,pStudentName);
    
    pfound = strstr(pInput,pStudentName);

    //nMarks
    int i=0;
    while(pfound[i+size_t+1] !=';'){
      if(pfound[i+size_t+1] == ' ' && (pfound[i+size_t+3]==',' || pfound[i+size_t+3]==';'))Student->nMarks++;
      i++;
    }

    //pMarks
    Student->pMarks = (int*)malloc(Student->nMarks*sizeof(int));
    int j=0;
    for(i=0;i<Student->nMarks;i++){
      while(pfound[j+size_t+1] != ';'){
	if(pfound[j+size_t+1]==' ' &&(pfound[j+size_t+3]==',' || pfound[j+size_t+3]==';')){
	  Student->pMarks[i] = atoi(&pfound[j+size_t+2]);
	  Student->AverageMark += Student->pMarks[i];
	  j +=2;
	  break;
	}
	j++;
      }
    }
    
    //AverageMark
    Student->AverageMark /= Student->nMarks;
    
  }else{ return 0; }

  return Student;
}
