#include <stdio.h>

#include <string.h>

#include <stdbool.h>

#define MAX_LENGTH 100
#define NUM_STRINGS 21

void add(char code[][8], char name[][NUM_STRINGS], double salary[], double allowance[], int * pn) {
  char ts[21];
  double g;
  int i, existed;
  printf("New Code(8 character) : ");
  fflush(stdin);
  gets(ts);
  strcpy(code[ * pn], ts);

  printf("New Name(20 character) : ");
  fflush(stdin);
  gets(ts);
  strcpy(name[ * pn], ts);
  printf("salary : ");
  scanf("%lf", & g);
  salary[ * pn] = g;
  printf("allowance : ");
  scanf("%lf", & g);
  allowance[ * pn] = g;
  ( * pn) ++;
  printf("Added!!\n\n");
}
void print(char name[MAX_LENGTH][NUM_STRINGS], char code[MAX_LENGTH][8], double salary[MAX_LENGTH],double allowance[MAX_LENGTH], int n ){
	for (int i=0; i<n; i++)
	{
		printf("\nName : %s \n  code : %s  \n  luong : %.2f  \n   tien thuong : %.2f\n",name[i],code[i],salary[i],allowance[i]);
	}
}
int main() {
  int n = 0;
  char code[MAX_LENGTH][8], name[MAX_LENGTH][NUM_STRINGS];
  double salary[MAX_LENGTH], allowance[MAX_LENGTH];
  int choose;

  do
  {
    printf("-----------------Menu-----------------\n");
    printf("1-Adding a new student\n");
    printf("2-Find data about students using a name inputted\n");
    printf("3-Remove an student based on a code inputted\n");
    printf("4-Print the list in descending order based on salary + allowance\n");
    printf("--------------------------------------\n");
    printf("Choose: ");
    fflush(stdin);
    scanf("%d", & choose);
    switch (choose) {
    case 1:
      if (n == MAX_LENGTH) printf("Can't Add anymore!\n");
      else add(code, name, salary, allowance, & n);
      xuat(name,code,salary,allowance,n);
      break;
    case 2:
      if (n == 0) printf("Nothing to search!\n");
      // else search(code, name, salary, allowance, & n);
      break;
    case 3:
      if (n == 0) printf("Nothing to deleted");
      // else deleted(code, name, salary, allowance, & n);
      break;
    case 4:
      if (n == 0) printf("Nothing to print");
      // else print(code, name, salary, allowance, & n);
      break;
    default:
      printf("Quit!\n");
      break;
    }
  } while (choose>=1&&choose<=4);
  
  return 0;
}