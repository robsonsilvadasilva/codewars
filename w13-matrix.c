#include <stdio.h>
#include <stdlib.h>

int ** matrix_multiplication(int **a, int **b, int n);

int main()
{
  int n;
  int i, j;

  int ** w;
  printf("Type the size of the matrix: \n");
  scanf("%d", &n);

  int ** a = (int**)malloc(sizeof(int*)*n);
  for (i=0; i<n; i++)
      a[i] = (int*)malloc(sizeof(int)*n);

  int ** b = (int **) malloc(sizeof(int*)*n);
  for (i=0; i<n; i++)
      b[i] = (int*)malloc(sizeof(int)*n);

  a[0][0] = 1;
  a[0][1] = 2;
  a[1][0] = 3;
  a[1][1] = 2;
  b[0][0] = 3;
  b[0][1] = 2;
  b[1][0] = 1;
  b[1][1] = 1;

  w = matrix_multiplication(a,b,n);

  printf("The multiplication Matrix:\n");
  for (i=0; i<n; i++){
      printf("\n");
      for(j=0;j<n;j++)
          printf(" %d |", w[i][j]);
  }
  return 0;
}

int ** matrix_multiplication(int **a, int **b, int n)
{
  int i,j,k;

  int ** r = (int**)malloc(sizeof(int*)*n);
  for (i=0; i<n; i++)
      r[i] = (int*)malloc(sizeof(int)*n);

  // Start the Matrix with 0;
  for(i=0;i<n;i++)
          for (j=0;j<n;j++)
              r[i][j] = 0;


  //Calculating the values:
  for(i=0;i<n;i++)
      for (j=0;j<n;j++)
              for (k=0; k<n; k++)
                  r[i][j] += a[i][k] * b[k][j];

  return r;

}
