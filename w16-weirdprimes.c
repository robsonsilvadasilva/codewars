#include<stdio.h>
#include<stdlib.h>

long long a(long long n);
long long g(long long n);
long long countOnes(long long n);
long long maxPn(long long n);
int anOverAverage(long long n);
unsigned int gcd(unsigned int u, unsigned int v);


int main()
{
  long long n;

  printf("Type the number n: ");
  scanf("%lld", &n);

  printf("%lld,", countOnes(n));

  /*printf("a(n):%d\n", a(n));
  printf("Number of ones: %lld\n", countOnes(n));
  printf("Max nprime: %lld\n", maxPn(n));
  printf("Average: %d\n", anOverAverage(n));*/
  printf("\n");
  return 0;
}

long long g(long long n)
{
  long long gnumber;

  if (n !=1 )
        gnumber = a(n) - a(n-1);
  else
    gnumber = 1;

  return gnumber;

}

long long a(long long n)
{
  long long f;

  if (n==1)
      return 7;
  else{
      f = a(n-1) + gcd(n, a(n-1));
  }

  return f;
}

unsigned int gcd(unsigned int u, unsigned int v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t;
        }
        v = v - u;
    } while (v != 0);
    return u << shift;
}

long long countOnes(long long n)
{
  long long ones = 0;
  int i, h, a;

  a = 7;
  for (i=2;i<=n;i++){
        h = gcd(i,a);
        if (h == 1)
              ones++;
        a = a + h;
  }
  return (ones+1);
}

long long maxPn(long long n)
{
  int primes[100];

  primes[1] = 5;
  primes[2] = 3;
  primes[3] = 11;
  primes[4] = 23;
  primes[5] = 47;
  primes[6] = 97;
  primes[7] = 101;

 return primes[n];
}

int anOverAverage(long long n)
{
  int avg;
  int sum = 0;
  int  index = 5;
  while (index <= n){
    index = 2*index + 1;
    while (index%2==0)
          index = 2*index + 1;
    sum = sum + index + 3;
  }

  avg = (countOnes(n) + sum)/n;

  return avg;

}
