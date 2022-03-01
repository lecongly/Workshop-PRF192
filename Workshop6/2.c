#include <stdio.h>

#include <stdbool.h>

#include <stdlib.h>

// Print array
void print(int * a, int * pn) {
  int i;
  for (i = 0; i < ( * pn); i++)
    printf("%3d", a[i]);
  printf("\n");
}
// Check array is Full ?
int isFull(int * a, int * pn) {
  int MAXN = 100; //maximum of 100 elements
  return (( * pn) == MAXN);
}
// Check array is Empty
int isEmpty(int * a, int * pn) {
  return (( * pn) == 0);
}
// Case1:
void add(int x, int * a, int * pn) {
  a[ * pn] = x;
  ( * pn) ++;
}
// Case2:
int posSearch(int x, int * a, int * pn, int * look) {
  int i, j = 0;
  for (i = 0; i < ( * pn); i++)
    if (a[i] == x) {
      look[j] = i;
      j++;
    }
  if (j == 0) printf("Not found\n");
  return j;
}
// Case4:
void inRage(int * a, int * pn) {
  int minVal, maxVal, i, temp;
  printf("minVal = ");
  scanf("%d", & minVal);
  printf("maxVal = ");
  scanf("%d", & maxVal);
  if (minVal > maxVal) {
    temp = minVal;
    minVal = maxVal;
    maxVal = temp;
  }
  for (i = 0; i < ( * pn); i++)
    if (a[i] >= minVal && a[i] <= maxVal) printf("%3d", a[i]);
  printf("\n");
}
// Case5:
void acSelectionSort(int * a, int * pn) {
  int i, j, c;
  for (i = 0; i < ( * pn) - 1; i++) {
    c = i;
    for (j = i + 1; j < ( * pn); j++)
      if (a[c] > a[j]) c = j;
    if (c > i) {
      j = a[c];
      a[c] = a[i];
      a[i] = j;
    }
  }
  print(a, pn);
}

int main() {
  int n = 0, value, m;
  int * a, * look;
  a = calloc(n + 1, sizeof(int));

  while (true) {
    a = (int * ) realloc(a, n + 1);
    look = calloc(n + 1, sizeof(int));
    int choose;

    printf("-----------------Menu-----------------\n");
    printf("1- Add a value\n");
    printf("2- Search a value\n");
    printf("3- Print out the array \n");
    printf("4- Print out the array in rages\n");
    printf("5- Print out the array in ascending order\n");
    printf("6- Quit\n");
    printf("--------------------------------------\n");
    printf("Choose: ");
    scanf("%d", & choose);
    switch (choose) {
    case 1:
      if (isFull(a, & n)) printf("Array is full\n\n");
      else {
        printf("Input an added value : ");
        scanf("%*c%d", & value);
        add(value, a, & n);
        printf("Added\n\n");
      }
      break;
    case 2:
      if (isEmpty(a, & n)) printf("Array is empty, please choose 1 to add values to array\n\n");
      else {
        printf("Input the searched value : ");
        scanf("%*c%d", & value);
        printf("Value at : ");
        value = posSearch(value, a, & n, look);
        for (m = 0; m < value; m++)
          printf("%3d", look[m]);
        printf("\n\n");
      }
      break;
    case 3:
      if (isEmpty(a, & n)) printf("Array is empty, please choose 1 to add values to array\n\n");
      else print(a, & n);
      break;
    case 4:
      if (isEmpty(a, & n)) printf("Array is empty, please choose 1 to add values to array\n\n");
      else inRage(a, & n);
      break;
    case 5:
      if (isEmpty(a, & n)) printf("Array is empty, please choose 1 to add values to array\n");
      else acSelectionSort(a, & n);
      break;
    case 6:
      printf("You choose quit the program\n");
      return 0;
    default:
      printf("Select [1 to 6] \n");
      break;
    }
  }
  return 0;
}