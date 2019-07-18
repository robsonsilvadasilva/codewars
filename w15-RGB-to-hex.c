#include <stdio.h>
#include <stdlib.h>

int rgb(int , int , int , char *);

int main()
{
  int r = -20;
  int g = 275;
  int b = 125;
  char * output;
  int hex;
  output = (char *)malloc(sizeof(char)*6);


  printf("%d %d %d\n", r, g, b);

  hex = rgb(r,g,b, output);

  for (int i=0;i<6;i++)
      printf("i: %c\n", output[i]);


  return 0;

}

int rgb(int r, int g, int b, char * output)
{

  r = r > 255 ? 255 : r < 0 ? 0 : r;
  g = g > 255 ? 255 : g < 0 ? 0 : g;
  b = b > 255 ? 255 : b < 0 ? 0 : b;

  /*output[0] = r/16;
  output[1] = r%16;
  output[2] = g/16;
  output[3] = g%16;
  output[4] = b/16;
  output[5] = b%16;

  int i = 0;
  for (i=0;i<6;i++){
    switch (output[i]){
      case 15:
        output[i] = 'F';
        break;
      case 14:
        output[i] = 'E';
        break;
      case 13:
        output[i] = 'D';
        break;
      case 12:
        output[i] = 'C';
        break;
      case 11:
        output[i] = 'B';
        break;
      case 10:
        output[i] = 'A';
        break;
      default:
        output[i] = output[i] + 48;
        break;
    }
  }*/

  sprintf(output, "%02.2X%02.2X%02.2X", r, g, b);

  return 0;

}
