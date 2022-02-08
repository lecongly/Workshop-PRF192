#include <stdio.h>

double makeDouble(int ipart, double fraction) {
  double d_f = fraction;
  while (d_f >= 1) d_f = d_f / 10; //create the fraction <1 
  if (ipart < 0) return ipart - d_f;
  return ipart + d_f;
}
int main() {
  int ipart;
  double fraction, value;
  printf("Enter ipart : ");
  scanf("%d", & ipart);
  do {
    printf("Enter fraction : ");
    scanf("%lf", & fraction);
  } while (fraction < 0);
  value = makeDouble(ipart, fraction);
  printf("%lf ", value);
  return 0;
}