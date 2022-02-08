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
// If n is prime number function return 1, is not return 0
}
int main() {
  int n, i;
  do {
    printf("Enter n (n>1):");
    scanf("%d", & n);
  } while (n < 2);
  for (i = 2; i < n; i++) {
    if (prime(i) == 1) {
      printf("%d ", i);
    }
  }
  return 0;
}