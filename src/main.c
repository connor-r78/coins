#include <stdio.h>
#include "circulate.h"
#include "cython.h"

int main(int argc, char** argv)
{
  if ( setupCython(argc, argv) ) return 1;

  create_circulator();
  predict_circulation();
}
