#include <stdio.h>


char getUserChoice() {
  char n;
  printf("==============\n");
  printf("1-Processing date data\n");
  printf("2-Character data\n");
  printf("3-Quit\n");
  printf("Choice [1..3] : ");
  scanf("%c", & n);
  return n;
}
void function3() {
  printf("Thank you for watching! Bye Bye!\n");
}
int validDate(int d, int m, int y) {
  int maxd = 31;
  if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1) return 0;
  if (m == 4 || m == 6 || m == 9 || m == 11) maxd = 30;
  else if (m == 2) {
    maxd = (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 29 : 28;
  }
  return d <= maxd;
}
void function1() {
  int d, m, y;
  printf("Input day, month, year:\n");
  scanf("%d %d %d", & d, & m, & y);
  if (!validDate(d, m, y)) printf("Invalid date\n");
  else printf("Valid date\n");
  printf("\n");
}
void function2() {
  char c1, c2, c;
  int i, t;
  printf("Input 2 character : ");
  scanf("%c%c%c", & c, & c1, & c2);

  if (c1 < c2) {
    t = c1;
    c1 = c2;
    c2 = t;
  }
  for (i = c1; i >= c2; i--) {
    printf("\n%c : %3d %3Xh", i, i, i);
  }
  printf("\n");
}

int main() {
  char maxChoice = '3';
  char userChoice;
  do {
    userChoice = getUserChoice();
    switch (userChoice) {
    case '1':
      function1();
      break;
    case '2':
      function2();
      break;
    case '3':
      function3();
      break;
    default:
      printf("Input 1 or 2 or 3 only!\n\n");
    }
  } while (userChoice != maxChoice);
  return 0;
}