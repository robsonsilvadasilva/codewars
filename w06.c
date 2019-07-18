#include <stdio.h>

/* sum 351, 26, 15 e 21.*/

typedef struct Pair Pair;
struct Pair {
    long long first;
    long long snd;
};

Pair ** removNb(int n, int * length);

int main()
{
  int n;
  int l = 2;
  int * length = &l;
  Pair * result;
  printf("Type the  number: ");
  scanf("%d", &n);

  result = removNb(n, length);

  printf("%lld %lld", result->first, result->snd);

  return 0;
}

Pair ** removNb(int n, int * length)
{
  int i, j, sum;
  i = 1;
  j = 1;
  sum = 0;
  Pair num;
  Pair * arr = &num;

  //int numbers[2] = {0,0};

  sum = ((1+n)*n)/2;

  printf("%d\n", sum);
  while(i != n)
  {
     for (j=1;j<i;j++)
     {
      if (i*j == (sum - (j+i)))
      {
        arr->first= j;
        arr->snd = i;
      }
    }
    i++;
  }

  if (arr->first != 0)
  {
    return arr;

  }
  else
  {
    printf("{}");
  }
}
