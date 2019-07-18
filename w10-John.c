#include <stdio.h>
#include <stdlib.h>

long long * john(long long n);
long long * ann(long long n);
long long sumAnn(long long n);
long long sumJohn(long long n);

int main()
{
  char w;
  long long n;
  long long * returned;
  int i = 0;

  printf("Type j, K, or a, b: ");
  scanf("%c %lld", &w, &n);

  if (w == 'j'){
      returned = john(n);
      while ( i < n){
        printf("%lld ", returned[i]);
        i++;
      }
  }

  else if (w == 'k')
      printf("%lld\n", sumJohn(n));

  else if (w == 'a'){
      returned = ann(n);
      while ( i < n){
        printf("%lld ", returned[i]);
        i++;
      }
  }

  else if (w == 'b')
      printf("%lld\n", sumAnn(n));

  else
        printf("Does not corresponding\n");

  return 0;
}

long long * john(long long n)
{
  int i;
  long long j[400], a[400];
  long long * result = j;

  j[0] = 0;
  a[0] = 1;

  for (i=1; i<n; i++){
    j[i] = (i - a[ j[i-1] ]);
    a[i] = (i - j[ a[i-1] ]);
  }

  return result;
}

long long sumJohn(long long n)
{
  int i;
  long long j[400], a[400];
  long long sum = 0;

  j[0] = 0;
  a[0] = 1;

  for (i=1; i<n; i++){
    j[i] = (i - a[ j[i-1] ]);
    a[i] = (i - j[ a[i-1] ]);
    sum = sum + j[i];
  }

  return sum;
}

long long * ann(long long n)
{
  int i;
  long long j[400], a[400];
  long long * result = a;

  j[0] = 0;
  a[0] = 1;

  for (i=1; i<n; i++){
    j[i] = (i - a[ j[i-1] ]);
    a[i] = (i - j[ a[i-1] ]);
  }

  return result;
}

long long sumAnn(long long n)
{
  int i;
  long long j[400], a[400];
  long long sum = 1;

  j[0] = 0;
  a[0] = 1;

  for (i=1; i<n; i++){
    j[i] = (i - a[ j[i-1] ]);
    a[i] = (i - j[ a[i-1] ]);
    sum = sum + a[i];
  }

  return sum;
}
