#include <stdlib.h>
#include <stdio.h>

void *getPage(FILE *file, unsigned int pageIndex, unsigned int pageSize);
int setPage(FILE *file, void *page, unsigned int pageIndex, unsigned int pageSize);
void *allocatePage(size_t pageSize);