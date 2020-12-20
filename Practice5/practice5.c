#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student{
  char *pName, *pCode;
  int mMathmatics,mPhysics,mChemistry;
  double Average;
}STUDENT;

STUDENT *Exam(char *pStudents, char *pMathmatics, char *pPhysics, char *pChemistry);


int main(){
  char Students[]="John Smith 25156IVSB; Mary Weaver 253742ABB; James Carpenter 252422TAF; Elizabeth Clerk 251443MV";
  char Mathmatics[]="James Carpenter 4; John Smith 5; Mary Weaver 4;  Elizabeth Clerk 2";
  char Physics[]="Mary Weaver 3; James Carpenter 2; Elizabeth Clerk 2; John Smith 5";
  char Chemistry[]="Elizabeth Clerk 4; John Smith 1; Mary Weaver 5;  James Carpenter 2";

  STUDENT *best_student;
  best_student = Exam(Students,Mathmatics,Physics,Chemistry);

  printf("---BEST STUDENT---\n");
  printf("NAME:%s\nCODE:%s\nAverage:%.3f\n",best_student->pName,
	 best_student->pCode,best_student->Average);

  free(best_student->pName);
  free(best_student->pCode);
  free(best_student);
  
  return 0;
}

STUDENT *Exam(char *pStudents, char *pMathmatics, char *pPhysics, char *pChemistry){
  
  if(pStudents==0||pMathmatics==0||pPhysics==0||pChemistry==0)return 0;
  
  int count_student=1;
  int i=0;
  while(pStudents[i]!='\0'){
    if(pStudents[i]==';')count_student++;
    i++;
  }
  
  STUDENT *result;
  result = (STUDENT*)malloc(sizeof(STUDENT)*count_student);
  int space=0;
  char* start;

  //Set the start flag at the beginning
  start = pStudents;

  int num=0;
  i=0;
  while(pStudents[i]!='\0'){
    
    if(pStudents[i]==' ')space++;
    if(space == 2){
      //First name + Last name = 2 spaces
      pStudents[i]='\0';
      result[num].pName=(char*)malloc(sizeof(char)*strlen(start));
      strcpy(result[num].pName,start);
      pStudents[i]=' ';
      
      start =&pStudents[i]+1;
      space=0;
    }
    if(pStudents[i]==';'){
      //Student Code
      pStudents[i]='\0';
      result[num].pCode=(char*)malloc(sizeof(char)*strlen(start)+1);
      strcpy(result[num].pCode,start);
      pStudents[i]=';';
      
      start =&pStudents[i]+2;
      space=0;

      //Proceed to the next Student
      num++;
    }
    if(pStudents[i+1]=='\0'){
      //Last Student Code
      result[num].pCode=(char*)malloc(sizeof(char)*strlen(start)+1);
      strcpy(result[num].pCode,start);
    }

    if(pStudents[i-1]==';'&&pStudents[i]==' ')space=0;
    i++;
  }

  //Score Calc
  char *p;
  for(i=0;i<count_student;i++){
    p=strstr(pMathmatics,result[i].pName);
    result[i].mMathmatics=atoi(p+strlen(result[i].pName)+1);

    p=strstr(pPhysics,result[i].pName);
    result[i].mPhysics=atoi(p+strlen(result[i].pName)+1);

    p=strstr(pChemistry,result[i].pName);
    result[i].mChemistry=atoi(p+strlen(result[i].pName)+1);
    
    result[i].Average=(double)(result[i].mMathmatics+result[i].mPhysics+result[i].mChemistry)/3;

    printf("---RESULT %d---\n",i+1);
    printf("NAME:%s\n",result[i].pName);
    printf("CODE:%s\n",result[i].pCode);
    printf("Math:%d\n",result[i].mMathmatics);
    printf("Physics:%d\n",result[i].mPhysics);
    printf("Chemistry:%d\n",result[i].mChemistry);
    printf("Average:%.3f\n\n",result[i].Average);
  }

  //Average Score Comparison
  //Same averages are not considered!
  int best;
  double compare=0;
  for(i=0;i<count_student;i++){
    if(compare < result[i].Average){
      compare=result[i].Average;
      best=i;
    }
  }

  //Annoying
  STUDENT *best_student = (STUDENT*)malloc(sizeof(STUDENT));
  best_student->pName=(char*)malloc(strlen(result[best].pName)+1);
  best_student->pCode=(char*)malloc(strlen(result[best].pCode)+1);
  strcpy(best_student->pName,result[best].pName);
  strcpy(best_student->pCode,result[best].pCode);
  best_student->mMathmatics = result[best].mMathmatics;
  best_student->mPhysics = result[best].mPhysics;
  best_student->mChemistry = result[best].mChemistry;
  best_student->Average = result[best].Average;				  
  
  for(i=0;i<count_student;i++){
      free(result[i].pName);
      free(result[i].pCode);
  }free(result);
  
  return best_student;
}
