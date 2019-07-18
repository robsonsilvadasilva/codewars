#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

char * rot13(const char * src);

int main()
{
  //int j;
  char src[200];
  char teste[200];
  char * str = teste;

  printf("Type the txt to chrypt: ");
  scanf("%[^\n]", src);

  str = rot13(src);

  printf("%s\n", str);

  free(str);

  return 0;
}

char * rot13(const char * src)
{
  int i = 0;
  char * cpt;

  while (src[i] != '\0')
      i++;


  cpt = malloc(sizeof(char)*i);

  i=0;
  while (src[i] != '\0')
  {
      cpt[i] = src[i];
      i++;
  }
  cpt[i] = '\0';


  printf("number of i before malloc: %d\n", i);

  i=0;
  while(cpt[i] != '\0'){
    if ( (cpt[i] >= 'a' && cpt[i] <= 'm') || (cpt[i] >= 'A' && cpt[i] <= 'M') ){
        cpt[i] = cpt[i] + 13;
        i++;
    }
    else if ( (cpt[i] >= 'n' && cpt[i] <= 'z') || (cpt[i] >= 'N' && cpt[i] <= 'Z') ){
        cpt[i] = cpt[i] - 13;
        i++;
    }
    else{
      i++;
    }

  }
  return (cpt);
}
