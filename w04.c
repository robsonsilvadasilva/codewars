#include <stdio.h>

int bouncingBall(double, double, double);

int main()
{
    double h, b, w;

    printf("Type height, bounce and window heiht:\n");
    scanf("%lf %lf %lf", &h, &b, &w);

    int result = bouncingBall(h, bounce, window);

    printf("%d\n", result);

    return 0;
}

int bouncingBall(double h, double bounce, double window){

  int views = 1;

  if (h>window)
  {
    h = h*bounce;
    while (h >= window)
    {
      h = h*bounce;
      views = views + 2;
    }
  }
  else
  {
    views = -1;
  }
  return views;
}
