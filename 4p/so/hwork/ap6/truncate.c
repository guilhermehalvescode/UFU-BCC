#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
  FILE *f = NULL;
  if ((f = fopen("./truncate.h", "w")) == NULL)
    return 1;

  const char data[11] = "12/10/2021";
  fwrite(data, sizeof(char), 10, f);

  fclose(f);

  if ((f = fopen("./truncate.h", "r")) == NULL)
    return 1;
  fseek(f, 0, SEEK_END);
  printf("Tamanho antes da truncagem: %ld\n", ftell(f));
  fclose(f);

  truncate("./truncate.h", sizeof(data) - 2);

  if ((f = fopen("./truncate.h", "r")) == NULL)
    return 1;
  fseek(f, 0, SEEK_END);
  printf("Tamanho depois da truncagem: %ld\n", ftell(f));
  return 0;
}