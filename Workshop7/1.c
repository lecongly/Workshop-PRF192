#include<stdio.h>

#include<string.h>

#include<windows.h>

#include <stdbool.h>

#define MAX_LENGTH 100
#define NUM_STRINGS 21

void add(char list[MAX_LENGTH][NUM_STRINGS], int * pn) {
  char hs[NUM_STRINGS];
  fflush(stdin);
  printf("Enter name students:");
  gets(hs);
  strcpy(list[ * pn], hs);
  ( * pn) ++;
  printf("Added\n");
}
void search(char list[MAX_LENGTH][NUM_STRINGS], int * pn) {
  int i;
  printf("Searching for : ");
  char hs[NUM_STRINGS];
  fflush(stdin);
  scanf("%s", hs);
  for (i = 0; i < * pn; i++) {
    char * ptr = strstr(list[i], hs);
    if (ptr != '\0') printf("RESULT : Name[%d] : %s\n", i, list[i]);
  }
}
void removed(char list[MAX_LENGTH][NUM_STRINGS], int * pn) {
  int del, i;
  for (i = 0; i < ( * pn); i++) {
    printf("Name[%d] : %s \n", i, list[i]);
  }
  printf("Which Name you want to removed?(input a number) : ");

  scanf("%d", & del);
  if (del >= 0 && del < * pn) {
    for (i = del + 1; i < * pn; i++)
      strcpy(list[i - 1], list[i]);
    printf("Removed!\n");
    ( * pn) --;
  } else printf("UnRemoved!\n");
}
void print(char list[MAX_LENGTH][NUM_STRINGS], int * pn) {
  int i, j;
  for (i = 0; i < * pn - 1; i++)
    for (j = * pn - 1; j > i; j--)
      if (strcmp(list[j], list[j - 1]) < 0) {
        char t[21];
        strcpy(t, list[j]);
        strcpy(list[j], list[j - 1]);
        strcpy(list[j - 1], t);
      }
  for (i = 0; i < ( * pn); i++) {
    printf("Name[%d] : %s \n", i, list[i]);
  }
}
int main() {
  int n = 0;
  char list[MAX_LENGTH][NUM_STRINGS];

  while (true) {
    int choose;

    printf("-----------------Menu-----------------\n");
    printf("|1- Add a student\n");
    printf("|2- Remove a student\n");
    printf("|3- Search a student \n");
    printf("|4- Print the list in ascending order\n");
    printf("|5- Quit\n");
    printf("--------------------------------------\n");
    printf("Choose: ");
    fflush(stdin);
    scanf("%d", & choose);
    switch (choose) {
    case 1:
      if (n == MAX_LENGTH) printf("Can't Add anymore!\n");
      else add(list, & n);
      system("pause");
      system("cls");
      break;
    case 2:
      if (n == 0) printf("Impossible to remove!\n");
      else removed(list, & n);
      system("pause");
      system("cls");
      break;
    case 3:
      if (n == 0) printf("Nothing to search!\n");
      else search(list, & n);
      system("pause");
      system("cls");
      break;
    case 4:
      if (n == 0) printf("Nothing to print!\n");
      else print(list, & n);
      system("pause");
      system("cls");
      break;
    case 5:
      return 0;
      break;
    default:
      printf("1 to 5 only!\n");
      system("pause");
      system("cls");
      break;
    }
  }
  return 0;
}