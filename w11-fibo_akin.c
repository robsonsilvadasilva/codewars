#include<stdio.h>

int lengthSupUK(int n, int k);
int comp(int n);

int main(){

  int n, k;

  printf("Type two integers number, n and k: ");
  scanf("%d %d", &n, &k);

  printf("Number of times n less than k: %d\n", lengthSupUK(n, k));

  printf("n less than predecessor: %d\n", comp(n));

  return 0;
}

int lengthSupUK(int n, int k){

  int i, cont;
  cont = 0;
  int u[100000];
  u[0] = 0;
  u[1] = u[2] = 1;

  for (i=3; i<=n;i++){
    u[i] = u[i - u[i-1]] + u[i - u[i-2]];
    if (u[i] >= k)
          cont++;
  }
  return cont;
}

int comp(int n){

  int i, cont;
  cont = 0;
  int u[100000];
  u[0] = 0;
  u[1] = u[2] = 1;

  for (i=3; i<=n;i++){
    u[i] = u[i - u[i-1]] + u[i - u[i-2]];
    if (u[i] < u[i-1])
          cont++;
  }
  return cont;
}
