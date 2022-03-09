#include <stdio.h>
#include <string.h>

#define MAXN 100

char getUserChoice() {
  char c;
  printf("1-Add a student\n");
  printf("2-Remove a student\n");
  printf("3-Search a student\n");
  printf("4-Print the list in ascending order\n");
  printf("5-Quit\n");
  printf("Choice = ");
  fflush(stdin);
  scanf("%c", & c);
  return c;
}
void add(){
  char hs[21];
  printf("Add a student : ");
	fflush(stdin);
	scanf("%20[^\n]", hs);
  printf("ADD\n");
}

int main() {
	char MAXCHOICE = '5';
  char userChoice;
  char list[MAXN][21];
  int n = 0;
  do {
    userChoice = getUserChoice();
    switch (userChoice) {
    case '1':
      add();
      break;
    case '2':
      
      break;
    case '3':
      
      break;
    case '4':
      
      break;
    case '5':
      return 0;
      break;
    }
    if (userChoice < '1' || userChoice > '5') printf("1 to 5 only!\n");
  } while (userChoice != MAXCHOICE);
}