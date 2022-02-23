#include <stdio.h>

#include <math.h>


char getUserChoice() {
  char n;
  printf("============\n");
  printf("1-Quadratic Equation\n");
  printf("2-Bank deposit\n");
  printf("3-Quit\n");
  printf("Choice [1..3] : ");
  scanf("%c", & n);
  return n;
}

void function1() {
  float a, b, c;
  printf("Input a b c : a*x^2 + b*x +c = 0 \n");
  scanf("%f%*c%f%*c%f", & a, & b, & c);
  if (a == 0) {
    if ((b == 0) && (c != 0)) printf("None of root!\n");
    else if ((c == 0) && (b == 0)) printf("Root in range of Real Number!\n");
    else printf("X = %0.3f\n", -c / b);
  } else {
    int delta;
    delta = b * b - 4 * a * c;
    if (delta < 0) printf("None of root!\n");
    else if (delta == 0) {
      printf("The Equation have double root : \n");
      printf("X = %0.3f\n", -b / 2 / a);
    } else {
      printf("The Equation have two root : \n");
      printf("X1 = %0.3f \n", (-b - sqrt(delta)) / 2 / a);
      printf("X2 = %0.3f \n", (-b + sqrt(delta)) / 2 / a);
    }
  }
  printf("\n");
}

void function2() {
  printf("Bank deposit \n");
  printf("============ \n");
  double deposit, rate, amount;
  int month, check;
  do {
    printf("Input your deposit , monthly rate and the number of months : ");
    check = scanf("%lf%*c%lf%*c%d", & deposit, & rate, & month);
    if (check != 3) printf("Retype 3 value please!\n");
    else {
      if (deposit <= 0) printf("Deposit must be positive!\n");
      if (month <= 0) printf("The number of months must be positive!\n");
      if (rate <= 0 || rate > 0.1) printf("Monthly rate must be positive but less than or equal to 0.1!\n");
    }
  } while (deposit <= 0 || month <= 0 || rate <= 0 || rate > 0.1 || check != 3);
  amount = (float) deposit * pow((1 + rate), month);
  printf("Your amount after duration : %f", amount);
  printf("\n");
}

void function3() {
  printf("Thank you for watching! Bye Bye!");
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
      printf("Input 1 or 2 or 3 only!\n");
    }
  } while (userChoice != maxChoice);
  return 0;
}