//Statistics for an Athletic Association
#include <stdio.h>
#include <string.h>

char * stat(char * strg);
void sort(int *, int);
void sectohour(int, int *);

int main()
{
  char string[200];
  char * strg = string;

  printf("Type the results: ");
  scanf("%[^\n]", strg);

  printf("%s", stat(strg));
  printf("\n");

  return 0;
}

char * stat(char * strg)
{
  int i, j, k, sum;
  i = j = k = 0;
  int n = 1;
  int arr[50], sec[50];
  char res[100];
  char * result = res;
  int range, avg, med;
  int arraya[3], arrayr[3], arraym[3];

  // Count numbers of entries:
  while (strg[i] != '\0')
  {
    if (strg[i] == ',')
    {
      n += 1;
    }
  i++;
  }

  //Convert entries to integers array:
  while (strg[j] != '\0')
  {
    if (strg[j] >= '0' && strg[j] <= '9' && strg[j+1] >= '0' && strg[j+1] <= '9')
    {
      arr[k] = (strg[j]-48)*10 + (strg[j+1]-48);
      j = j + 2;
      k++;
    }
    else if ( (strg[j] >= '0' && strg[j] <= '9') || (strg[j+1] == '|') || (strg[j+1] == ','))
    {
      arr[k] = (strg[j]-48);
      j++;
      k++;
    }
    else if ((strg[j] >= '0' && strg[j] <= '9') && (strg[j+1] == '\0'))
    {
      arr[k] = (strg[j]-48);
      j++;
      k++;
    }
    else
    {
      j++;
    }
  }
      //01|15|59, 1|47|6, 01|17|20, 1|32|34, 2|3|17
  j = 0;
  sum = 0;
  for (k=0; k < (n*3); k = k + 3)
  {
    sec[j] = (arr[k]*3600 + arr[k+1]*60 + arr[k+2]);
    sum = sum + sec[j];
    j++;
  }

  sort(sec,n);

  range = sec[n-1] - sec[0];
  sectohour(range, arrayr);

  avg = sum/n;
  sectohour(avg, arraya);

  if (n%2 == 0)
    {
      n = n/2;
      med = (sec[n-1] + sec[n])/2;
    }
    else
    {
      n = n/2;
      med = sec[n];
    }

  sectohour(med, arraym);

  sprintf(result,"Range: %.2d|%.2d|%.2d Average: %.2d|%.2d|%.2d Median: %.2d|%.2d|%.2d",
  arrayr[0], arrayr[1], arrayr[2], arraya[0], arraya[1], arraya[2],
  arraym[0], arraym[1], arraym[2]);

  return result;
}

void sort(int * sec, int n)
{
  int i, j, swap;
  i = j = 0;
  for (i=0; i<n;i++)
  {
    for (j=i+1; j<n; j++)
    {
      if (sec[i] > sec[j])
      {
         swap = sec[i];
         sec[i] = sec[j];
         sec[j] = swap;
      }
    }
  }
}

void sectohour(int number, int * array)
{
  int rest;

  if (number > 3600)
  {
    array[0] = number/3600;
    rest = number%3600;
    array[1] = rest/60;
    rest = rest%60;
    array[2] = rest;
  }
  else if (number > 60)
  {
    array[0] = 0;
    array[1] = number/60;
    array[2] = number%60;
  }
  else
  {
    array[0] = 0;
    array[1] = 0;
    array[2] = number;
  }

}
