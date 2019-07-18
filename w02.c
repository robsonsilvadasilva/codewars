/*Given two numbers and an arithmetic operator (the name of it, as a string),
 * return the result of the two numbers having that operator used on them.
 * a and b will both be positive integers, and a will always be the first
 * number in the operation, and b always the second.
 * The four operators are "add", "subtract", "divide", "multiply".
 * A few examples:
 * arithmetic(5, 2, "add")      => returns 7
arithmetic(5, 2, "subtract") => returns 3
arithmetic(5, 2, "multiply") => returns 10
arithmetic(5, 2, "divide")   => returns 2.5*/

#include <stdio.h>

double arithmetic(double , double ,char *);

int main ()
{
  int i;
  double result, a,b;
  char * operator;

  scanf("%lf %lf %s", &a, &b, operator);

  while (operator [i] != '\0')
    {
      printf("%c\n", operator[i]);
      ++i;
    }

  result = arithmetic(a,b,operator);

  printf("%.1lf\n", result);

  return 0;
}

double arithmetic(double a, double  b, char * operator)
{
  double value;
  int i = 0;

  if (operator[0] == 'a')
    {
      value = a + b;
    }
  else if (operator[0] == 's')
    {
      value = a - b;
    }
  else if (operator[0] == 'm')
    {
      value = a * b;
    }
  else if (operator[0] == 'd')
    {
      value = a / b;
    }
    else
      {
         printf("invalid datas");
      }

  return value;
}
