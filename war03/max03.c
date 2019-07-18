int maxMultiple(int divisor, int bound)
{
  int i;
  i = bound;

  while (i%divisor != 0)
    {
      i = (i-1);
    }

  return i;

}
