#include "./heapFile/index.h"

int main()
{
  HEAP_FILE file = createHeapFile(NUM_REGISTERS);

  if (file == NULL)
  {
    return -1;
  }

  fclose(file);
  return 0;
}