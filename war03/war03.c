#include <stdio.h>
#include "max03.h"

int main()
{
  int  divisor, bound, result;

  scanf("%d %d", &divisor, &bound);

  result = maxMultiple(divisor,bound);

  printf("%d\n", result);


  return 0;
}
