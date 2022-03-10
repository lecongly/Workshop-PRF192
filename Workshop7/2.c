#include <stdio.h>

#include <string.h>

#include <stdbool.h>

#define MAX 100

void add(char code[][8], char name[][21], double salary[], double allowance[], int * pn) {
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
void search(char code[][8], char name[][21], double salary[], double allowance[], int * pn) {
  int i;
  printf("Searching for : ");
  char nv[21];
  fflush(stdin);
  gets(nv);
  for (i = 0; i < * pn; i++) {
    int j;
    char * ptr = strstr(name[i], nv);
    if (ptr != '\0') printf("RESULT :[%d] := Code:%8s|Name:%20s|salary:%3.3lf|allowance:%3.3lf \n", i, code[i], name[i], salary[i], allowance[i]);
  }
}
void deleted(char code[][8], char name[][21], double salary[], double allowance[], int * pn) {
  int i, j;
  for (i = 0; i < * pn; i++)
    printf("Code:%8s|Name:%20s|salary:%3.3lf|allowance:%3.3lf \n", code[i], name[i], salary[i], allowance[i]);
  char del[8];
  fflush(stdin);
  printf("Code for deleted(Success only when code exist) : ");
  scanf("%8[^\n]", & del);

  for (i = 0; i < * pn; i++)
    if (strcmp(code[i], del) == 0) {
      for (j = i + 1; j < * pn; j++) {
        strcpy(name[i - 1], name[i]);
        strcpy(code[i - 1], code[i]);
        salary[i - 1] = salary[i];
        allowance[i - 1] = allowance[i];
      }
      ( * pn) --;
      printf("Success!\n\n");
    }

}
void print(char code[][8], char name[][21], double salary[], double allowance[], int * pn) {

  int i, j;
  for (i = 0; i < * pn - 1; i++)
    for (j = * pn - 1; j > i; j--)
      if ((salary[j] + allowance[j]) > (salary[j - 1] + allowance[j - 1])) {
        char t[21];
        strcpy(t, name[j]);
        strcpy(name[j], name[j - 1]);
        strcpy(name[j - 1], t);

        char tu[8];
        strcpy(tu, code[j]);
        strcpy(code[j], code[j - 1]);
        strcpy(code[j - 1], tu);

        double tg = salary[j];
        salary[j] = salary[j - 1];
        salary[j - 1] = tg;

        double tb = allowance[j];
        allowance[j] = allowance[j - 1];
        allowance[j - 1] = tb;
      }
  for (i = 0; i < * pn; i++)
    printf("Code:%8s|Name:%20s|salary:%3.3lf|allowance:%3.3lf \n", code[i], name[i], salary[i], allowance[i]);

}
int main() {
  int n = 0;
  char code[MAX][8], name[MAX][21];
  double salary[MAX], allowance[MAX];
  int choose;

  do {
    printf("-----------------Menu-----------------\n");
    printf("|1-Adding a new employee\n");
    printf("|2-Find data about employee using a name inputted\n");
    printf("|3-Remove an employee based on a code inputted\n");
    printf("|4-Print the list in descending order based on salary + allowance\n");
    printf("|(Anykey to quit!!)\n");
    printf("--------------------------------------\n");
    printf("Choose: ");
    fflush(stdin);
    scanf("%d", & choose);
    switch (choose) {
    case 1:
      if (n == MAX) printf("Can't Add anymore!\n");
      else add(code, name, salary, allowance, & n);
      system("pause");
      system("cls");
      break;
    case 2:
      if (n == 0) printf("Nothing to search!\n");
      else search(code, name, salary, allowance, & n);
      system("pause");
      system("cls");
      break;
    case 3:
      if (n == 0) printf("Nothing to deleted");
      else deleted(code, name, salary, allowance, & n);
      system("pause");
      system("cls");
      break;
    case 4:
      if (n == 0) printf("Nothing to print");
      else print(code, name, salary, allowance, & n);
      system("pause");
      system("cls");
      break;
    default:
      printf("Quit!\n");
      break;
    }
  } while (choose >= 1 && choose <= 4);

  return 0;
}