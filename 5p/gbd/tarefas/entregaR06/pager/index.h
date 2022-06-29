#include <stdlib.h>
#include <stdio.h>

void *getPage(FILE *file, off_t pageIndex, size_t pageSize);
void *setPage(FILE *file, void *page, off_t pageIndex, off_t pageSize);
void *allocatePage(size_t pageSize);