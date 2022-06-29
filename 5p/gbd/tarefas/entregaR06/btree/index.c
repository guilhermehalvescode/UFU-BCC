#include <stdio.h>

FILE *openPageFile(long int pageSize)
{
  FILE *file;
  // if file exists, open it
  if ((file = fopen("./heapFile.bin", "r+b")) != NULL)
  {
    return file;
  }

  // else create it
  if ((file = fopen("./heapFile.bin", "w+b")) == NULL)
  {
    perror("[ERROR] createHeapFile fopen as write binary heapFile");
    return NULL;
  }

  return file;
}
