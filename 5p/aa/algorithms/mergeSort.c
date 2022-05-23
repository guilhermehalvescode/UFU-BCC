#include <stdio.h>
#include <stdlib.h>

int merge(int *v, int start, int mid, int end)
{
  int
      aux,              // auxiliary for iterating
      auxStart = start, // auxStart is the position of the first element of the first half
      auxMid = mid + 1, // auxMid is the position of the first element of the second half
      auxCount = 0;     // count ordered size

  // orderedArray is the array that will contain the ordered elements
  int *orderedArr = (int *)malloc((end - start + 1) * sizeof(int));

  if (orderedArr == NULL)
    return -1;

  // select the lowest element from both arrays and put it in the ordered array
  // printf("original arr before merge:\n");
  // printArr(v, end + 1);
  while (auxStart <= mid && auxMid <= end)
  {
    orderedArr[auxCount++] =
        v[auxStart] < v[auxMid]
            ? v[auxStart++]
            : v[auxMid++];
  }

  // printf("ordered arr before inserting last elements:\n");
  // printArr(orderedArr, auxCount);

  // if the first half remain elements, put them in the ordered array
  while (auxStart <= mid)
  {
    orderedArr[auxCount++] = v[auxStart++];
  }

  // if the second half remain elements, put them in the ordered array
  while (auxMid <= end)
  {
    orderedArr[auxCount++] = v[auxMid++];
  }

  // printf("ordered arr after inserting last elements:\n");
  // printArr(orderedArr, auxCount);
  // send the ordered elements in the orderedArray to the original array
  for (aux = 0; aux < auxCount; aux++)
  {
    v[aux + start] = orderedArr[aux];
  }

  // printf("original array after merge:\n");
  // printArr(v, end + 1);

  // remove allocated mem for temp orderedArray
  free(orderedArr);
  return 1;
}

int mergeSort(int *v, int start, int end)
{
  if (start < end)
  {
    int mid = (start + end) / 2;
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    merge(v, start, mid, end);
  }
  return 1;
}
