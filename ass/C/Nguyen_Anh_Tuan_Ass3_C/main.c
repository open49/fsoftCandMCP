/******************************************************************************
*INCLUDEs
******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
/******************************************************************************
*FUNCTION
******************************************************************************/
bool allocate10Bytes(uint8_t *outPtr){
  uint8_t** outPtr1 = (uint8_t**)(outPtr);
  *outPtr1 = malloc(10 * sizeof(uint8_t));

  if (*outPtr1 == NULL) {
    return false;
  }

  return true;
}
/******************************************************************************
*MAIN
******************************************************************************/

int main(void) {
  uint8_t* Ptr_Output = NULL;

  bool status = allocate10Bytes((uint8_t*)&Ptr_Output);

  if (status)
  Ptr_Output[9]  = 10;
  
  free(Ptr_Output);
  return 0;
}


/******************************************************************************
*END OF FILE
******************************************************************************/
