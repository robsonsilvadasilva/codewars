#include<stdio.h>
#include<stdbool.h>

bool alphanumeric(const char* strin);

int main()
{
  char s[100];
  char * ptr = s;
  scanf("%[^\n]", ptr);

  printf("%d", alphanumeric(ptr));

}

bool alphanumeric(const char* strin)
{
  int comp, i,j;
  comp = 0;
  i=0;
  while (strin[i] != '\0')
      i++;

  if (i==0)
      return 0;

  for (j=0; j<i;j++){
    if ((strin[j] >= 65 && strin[j] <= 90) || (strin[j] >= 97 && strin[j] <= 122)
    || (strin[j] >= 48 && strin[j] <= 57))
        comp++;
    else
      return 0;
  }

  if (comp == i)
      return 1;
    else
      return 0;
}
