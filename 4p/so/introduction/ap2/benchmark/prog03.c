/* prog03.c */
#include <stdio.h>
#include <string.h>
main()
{
  int i;
  char str[20001] = "";
  for (i = 0; i < 10000; i += 2)
  {
    *(str + i) = 'A';
    *(str + i + 1) = '\n';
  }
  *(str + i) = '\0';
  printf("%s", str);
}