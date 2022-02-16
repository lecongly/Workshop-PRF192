#include <stdio.h>

#include <math.h>

int prime(int n) {
  int m = sqrt(n);
  int i;
  if (n < 2) return 0;
  for (i = 2; i <= m; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void printMinMaxDigits(int n) {
  // Example n = 10293
  int digit; /* Variable for extracting 1 digit */
  int min, max; /* Result variables */
  digit = n % 10; /* get the first rightmost digit: 3 */
  n = n / 10; /* 1029, the remainder needs to proceed after*/
  min = max = digit; /* initialize results */
  while (n > 0) {
    digit = n % 10; /* Get the next digit */
    n = n / 10;
    if (min > digit) min = digit; /* update results */
    if (max < digit) max = digit;
  }
  printf("Max digit : %d\n", max);
  printf("Min digit : %d\n", min);
}
int main() {
  int choice, n;
  do {
    printf("=========MENU==========\n");
    printf("1- Process primes\n");
    printf("2- Print min, max digit in an integer \n");
    printf("3- Quit\n");
    printf("Select an operation:");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      do {
        printf("Enter n: \n");
        scanf("%d", & n);
      } while (n < 0);
      if (prime(n) == 1) {
        printf("%d is a prime\n", n);
      } else {
        printf("%d is not a prime\n", n);
      }
      break;
    case 2:
      do {
        printf("Enter n: \n");
        scanf("%d", & n);
      } while (n < 0);
      printMinMaxDigits(n);

    case 3:
      break;
    }
  } while (choice > 0 && choice < 3);
  return 0;
}