#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char ** movingShift(char* strng, int shift);
char * demovingShift(char ** s, int shift);

int main(){

  int shift = 1;
  char strin [100];
  char * s = strin;
  char ** ptr;
  char * returned;
  returned = (char *)malloc(sizeof(char)*100);


  printf("Type the phrase to encrypt: ");
  scanf("%[^\n]", s);

  ptr = movingShift(s, shift);

  printf("main1: %s\n", ptr[0]);
  printf("main2: %s\n", ptr[1]);
  printf("main3: %s\n", ptr[2]);
  printf("main4: %s\n", ptr[3]);
  printf("main5: %s\n", ptr[4]);

  returned = demovingShift(ptr, shift);

  printf("Decrypt: %s", returned);

  free(ptr);
  free(returned);

  return 0;
}

char ** movingShift(char * strng, int shift)
{
  int i, j, k;
  int r;
  int dd;
  char * v;
  char ** w = (char**)malloc(sizeof(char*)*5);
  for (i=0; i<5; i++)
        w[i] = (char*)malloc(sizeof(char)*20);

  for (i=0; i<5; i++)
        for (j=0;j<20;j++)
              w[i][j] = '\0';

  i = 0;
  while (strng[i] != '\0')
        i++;

  if (i%5 == 0){
    dd = i/5;
  }
  else{
    dd = i/5 + 1;
  }

  v = (char *) malloc(sizeof(char)*i);

  for (j=0; j<i; j++){
    r = strng[j] + shift;
    if (strng[j] >= 'a' && strng[j] <= 'z'){
      while(r > 122)
          r = r - 26;
      v[j] = r;
      shift++;
    }
    else if (strng[j] >= 'A' && strng[j] <= 'Z'){
      while(r > 90)
          r = r - 26;
      v[j] = r;
      shift++;
    }
    else{
      v[j] = strng[j];
      shift++;
    }
  }
  v[j] = '\0';

  j = 0;
  for (i=0; i<5 && (v[j] != '\0'); i++){
    for (k=0; k<dd && (v[j] != '\0'); k++){
            w[i][k] = v[j];
            j++;
    }
  }

  return w;
}

char * demovingShift(char ** s, int shift)
{
  int i, j, k, r;
  char * u;

  u = (char*)malloc(sizeof(char)*100);
  k=0;
  for (i=0; i<5; i++)
        for(j=0; j<20 && (s[i][j] != '\0'); j++){
          u[k] = s[i][j];
          k++;
        }
  u[k] = '\0';
  i=0;
  while (u[i] != '\0')
        i++;

  printf("%s\n", u);
  j=0;
  for (j=0; j<i; j++){
    r = u[j] - shift;
    if (u[j] >= 'a' && u[j] <= 'z'){
        while(r < 97)
            r = r + 26;
        u[j] = r;
        shift++;
    }
    else if (u[j] >= 'A' && u[j] <= 'Z'){
        while(r < 65)
          r = r + 26;
        u[j] = r;
        shift++;
    }
    else{
      shift++;
    }
  }
  u[j] = '\0';

  return u;
}
