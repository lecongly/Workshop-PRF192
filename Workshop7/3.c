#include<stdio.h>

#include<string.h>

#include<windows.h>

#define MAX 100

void add(char name[MAX][21], char make[MAX][21], int volume[MAX], int price[MAX], int duration[MAX], int * pn) {
  char ts[21];
  int volumet, pricet, durationt;
  printf("New Drink : ");
  fflush(stdin);
  gets(ts);
  strcpy(name[ * pn], ts);
  printf("Make : ");
  fflush(stdin);
  gets(ts);
  strcpy(make[ * pn], ts);
  printf("volume : ");
  scanf("%d", & volumet);
  volume[ * pn] = volumet;
  printf("price : ");
  scanf("%d", & pricet);
  price[ * pn] = pricet;
  printf("duration : ");
  scanf("%d", & durationt);
  duration[ * pn] = durationt;
  ( * pn) ++;
  printf("Added!!\n\n");
}
void searchByName(char name[MAX][21], char make[MAX][21], int volume[MAX], int price[MAX], int duration[MAX], int * pn) {
  int i;
  printf("Searching for : ");
  char dn[21];
  fflush(stdin);
  gets(dn);
  for (i = 0; i < * pn; i++) {
    int j;
    char * ptr = strstr(name[i], dn);
    if (ptr != '\0') printf("RESULT :[%d] := Name:%8s|Make:%20s|Volume:%3.3d|Price:%3.3d|Duration:%3.3d \n", i, name[i], make[i], volume[i], price[i], duration[i]);
  }
}
void searchByVolume(char name[MAX][21], char make[MAX][21], int volume[MAX], int price[MAX], int duration[MAX], int * pn) {
  int v1, v2, i;
  printf("\nEnter v1 and v2 :  ");
  scanf("%d%d", & v1, & v2);
  for (i = 0; i < * pn; i++) {
    if (volume[i] >= v1 && volume[i] <= v2) {
      printf(" %s   %s   %d   %d   %d", name[i], make[i], volume[i], price[i], duration[i]);
    }
  }
}
void print(char name[MAX][21], char make[MAX][21], int volume[MAX], int price[MAX], int duration[MAX], int * pn) {

  int i, j;
  for (i = 0; i < * pn - 1; i++)
    for (j = * pn - 1; j > i; j--)
      if ((volume[j] + price[j]) > (volume[j - 1] + price[j - 1])) {
        char t[21];
        strcpy(t, name[j]);
        strcpy(name[j], name[j - 1]);
        strcpy(name[j - 1], t);

        char tm[8];
        strcpy(tm, make[j]);
        strcpy(make[j], make[j - 1]);
        strcpy(make[j - 1], tm);

        int tv = volume[j];
        volume[j] = volume[j - 1];
        volume[j - 1] = tv;

        int tp = price[j];
        price[j] = price[j - 1];
        price[j - 1] = tp;

        int td = duration[j];
        duration[j] = duration[j - 1];
        duration[j - 1] = td;

      }
  for (i = 0; i < * pn; i++)
    printf("[%d] := Name:%8s|Make:%20s|Volume:%3.3d|Price:%3.3d|Duration:%3.3d \n", i, name[i], make[i], volume[i], price[i], duration[i]);

}
int main() {
  int n = 0;
  char name[MAX][21], make[MAX][21];
  int volume[MAX], price[MAX], duration[MAX];
  int choose;

  do {
    printf("-----------------Menu-----------------\n");
    printf("1. Add a new softdrink\n");
    printf("2. Search items by make\n");
    printf("3. Search items by volume range\n");
    printf("4. Print the list order by volume then price\n");
    printf("5. Quit\n");
    printf("--------------------------------------\n");
    printf("Choose: ");
    fflush(stdin);
    scanf("%d", & choose);
    switch (choose) {
    case 1:
      if (n == MAX) printf("Can't Add anymore!\n");
      else add(name, make, volume, price, duration, & n);
      system("pause");
      system("cls");
      break;
    case 2:
      if (n == 0) printf("Nothing to search!\n");
      else searchByName(name, make, volume, price, duration, & n);
      system("pause");
      system("cls");
      break;
    case 3:
      if (n == 0) printf("Nothing to search!\n");
      else searchByVolume(name, make, volume, price, duration, & n);
      system("pause");
      system("cls");
      break;
    case 4:
      if (n == 0) printf("Nothing to print");
      else print(name, make, volume, price, duration, & n);
      system("pause");
      system("cls");
      break;
    default:
      printf("Quit!\n");
      break;
    }
  } while (choose >= 1 && choose <= 4);

  return 0;
}