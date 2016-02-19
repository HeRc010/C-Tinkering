#include "stdio.h"
#include "stdlib.h"

int main()
{
  printf("Test Test.\n");

  const unsigned ARRAY_SIZE = 10;
  
  int *array = (int *) malloc(ARRAY_SIZE * sizeof(int));

  int *ptr = array;
  int i = 0;
  for (i = 0; i < ARRAY_SIZE; ++i)
  {
    *(ptr++) = i;
  }

  // Print values
  ptr = array;
  for (i = 0; i < ARRAY_SIZE; ++i)
  {
    printf("%d ", *(ptr++));
  }
  
  printf("\n");
    
  free(array);
  
  return 0;
}
