#include <stdio.h>

char * alphabet_war(const char *);

int main()
{
  char fight[200];

  scanf("%s", fight);

  printf("%s", alphabet_war(fight));

  return 0;
}

char * alphabet_war(const char * fight)
{
  int i, j;
  char bat[200];
  i = j = 0;
  int left, right;
  left = right = 0;

  while (fight[i] != '\0')
  {
    bat[i] = fight[i];
    ++i;
  }

  for (j=0; j<i; j++)
  {
    if (bat[j] == '*' && bat[j+1] == '*' && j == 0)
    {
      bat[j] = '#';
    }
    else if (bat[j] == '*' && bat[j+1] == '*' && j > 0)
    {
      bat[j-1] = '#';
    }
    else if (bat[j] == '*' && j == 0)
    {
      bat[j+1] = '#';
    }
    else if (bat[j] == '*' && j > 0)
    {
      bat[j-1] = '#';
      bat[j+1] = '#';
    }
  }


  for (j=0; j<i; j++)
  {
    switch (bat[j])
    {
      case 'w':
        left += 4;
        break;
      case 'p':
        left += 3;
        break;
      case 'b':
        left += 2;
        break;
      case 's':
        left += 1;
        break;

      case 'm':
        right += 4;
        break;
      case 'q':
        right += 3;
        break;
      case 'd':
        right += 2;
        break;
      case 'z':
        right += 1;
        break;
      default:
        break;
    }
  }

  if (left>right)
  {
    return "Left side wins!";
  }
  else if (left == right)
  {
    return "Let's fight again!";
  }
  else
  {
    return "Right side wins!";
  }

}
