#include <stdio.h>

void printFibonacciNumbers(int n) {
  int f1 = 0, f2 = 1, i;

  if (n < 1)
    return;
  printf("%d ", f1);
  for (i = 1; i < n; i++) {
    printf("%d ", f2);
    int next = f1 + f2;
    f1 = f2;
    f2 = next;
  }
}
int validDate(int d, int m, int y) {
  int maxd = 31;
  if (d < 1 || d > 31 || m < 1 || m > 12) return 0;
  if (m == 4 || m == 6 || m == 9 || m == 11) maxd = 30;
  else if (m == 2) {
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) maxd = 29;
    else maxd = 28;
  }
  return d <= maxd;
}

int main() {
  int choice, n;
  int d, m, y;
  do {
    printf("\n=========MENU==========\n");
    printf("1- Print n first Fibonacci numbers\n");
    printf("2- Valid Date \n");
    printf("3- Quit\n");
    printf("Select an operation:");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      do {
        printf("Enter n: \n");
        scanf("%d", & n);
      } while (n < 0);
      printFibonacciNumbers(n);
      break;
    case 2:
      printf("Please enter day, month, year need valid: ");
      scanf("%d%d%d", & d, & m, & y);
      if (validDate(d, m, y)) {
        printf("Valid Date");
      } else {
        printf("Invalid Date");
      }
      case 3:
        break;
    }
  } while (choice > 0 && choice < 3);
  return 0;
}