#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  int day;
  char month[4];
  int year;
} DATE;

typedef struct{
  const char *pFirstName, *pLastName, *pNationality;
  DATE Birthdate;
} STUDENT;

int Exam(STUDENT *pStudents, int nStudents, const char *pPattern);
char *Month(STUDENT *pStudents, int num);

int main(){
  STUDENT students[]={{"John","Smith","Britain",{1,"Feb",2000}},
                      {"Mary","Weaver","USA",{2,"Mar",2001}},
                      {"James","Carpenter","Canada",{11,"Oct",2002}},
                      {"Elizabeth","Clerk","Ireland",{21,"Dec",2001}}};
  const char *ptoSearch = "Carpenter, James born 11 October 2002 from Canada";

  printf("%d\n",Exam(students,4,ptoSearch));

  return 0;
}

int Exam(STUDENT *pStudents, int nStudents, const char *pPattern){
  char search_str[256];
  char *month;
  int i;

  for(i=0; i<nStudents; i++){
    month = Month(pStudents, i);
    sprintf(search_str,"%s, %s born %d %s %d from %s",pStudents[i].pLastName,
            pStudents[i].pFirstName,
            pStudents[i].Birthdate.day,
            month,pStudents[i].Birthdate.year,
            pStudents[i].pNationality);
    if(strcmp(search_str,pPattern)==0){
      printf("The student has been found!\n");
      return 1;
    }
  }

  return 0;
}

char *Month(STUDENT *pStudents, int num){
  char *month;
  int i;
  char months[][64]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

  for(i=0;i<12;i++){
    if(strcmp(pStudents[num].Birthdate.month,months[i]) == 0){
      switch(i){
        case 0:
          month = "January";
          break;
        case 1:
          month = "February";
          break;
        case 2:
          month = "March";
          break;
        case 3:
          month = "April";
          break;
        case 4:
          month = "May";
          break;
        case 5:
          month = "June";
          break;
        case 6:
          month = "July";
          break;
        case 7:
          month = "August";
          break;
        case 8:
          month = "September";
          break;
        case 9:
          month = "October";
          break;
        case 10:
          month = "November";
          break;
        case 11:
          month = "December";
          break;
      }
    }
  }
    return month;
}
