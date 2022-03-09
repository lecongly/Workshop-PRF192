#include <stdio.h>

char getUserChoice() {
  char c;
  printf("1-Add a student\n");
  printf("2-Remove a student\n");
  printf("3-Search a student\n");
  printf("4-Print the list in ascending order\n");
  printf("5-Quit\n");
  printf("Choice = ");
  scanf("%c", & c);
  return c;
}
int main() {
	char MAXCHOICE = '5';
  char userChoice;
  char list[100][21];
  int n = 0;
  do {
    userChoice = getUserChoice();
    switch (userChoice) {
    case '1':
      // if (isFull(list, & n)) printf("Impossible to add!\n");
      // else add(list, & n);
      break;
    case '2':
      // if (isEmpty(list, & n)) printf("Impossible to remove!\n");
      // else removed(list, & n);
      break;
    case '3':
      // if (isEmpty(list, & n)) printf("Nothing to search!\n");
      // else search(list, & n);
      break;
    case '4':
      // if (isEmpty(list, & n)) printf("Nothing to print!\n");
      // else print(list, & n);
      break;
    case '5':
      break;
    }
    if (userChoice < '1' || userChoice > '5') printf("1 to 5 only!\n");
  } while (userChoice != MAXCHOICE);
}