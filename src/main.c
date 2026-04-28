#include <stdio.h>
#include <stdlib.h>

#include "circulate.h"
#include "cython.h"

#include "LinkedList.h"

struct State {
  struct LinkedList coinPops; 
};

int main(int argc, char** argv)
{
  if ( setupCython(argc, argv) ) return 1;

  create_circulator();
  predict_circulation();
}
