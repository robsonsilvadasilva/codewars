#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int comp(int *pa, int *pb, int n);

int main()
{
  int a[8] = {121, 144, 19, 161, 19, 144, 19, 11};
  int b[8] =  {14641, 20736, 361, 25921, 361, 20736, 361, 121};
  int n = 8;

  int * pa = a;
  int * pb = b;

  int result = comp(pa,pb,n);
  printf("%d\n", result);

  return 0;
}

int comp(int *pa, int *pb, int n)
{
  int i, j;
  int a[n];
  int b[n];

  for (i=0; i<n; ++i)
  {
    a[i] = 0;
    b[i] = 0;
  }

  for (i=0; i<n; ++i)
    {
      for(j=0; j<n; ++j)
      {
        if ( (pa[i]*pa[i]) == pb[j] && b[j] != 1)
        {
          a[i] = 1;
          b[j] = 1;
          break;
        }
      }
    }

  for (i=0; i<n; i++)
  {
    printf("s: %d v: %d \n", a[i], b[i]);
  }

  for (i=0; i<n; i++)
  {
    if (a[i] == 0 || b[i] == 0)
    {
      return 0;
    }
  }
  return 1;


}
