#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "circulate.h"
#include "cython.h"

#include "LinkedList.h"

struct State {
  struct LinkedList coinPops; 
};

int main(int argc, char** argv)
{
  if ( setupCython(argc, argv) ) return 1;

  int opt;
  while ( (opt = getopt(argc, argv, "rt")) != -1 ) {
    switch ( opt ) {
    case 'r':
      load_circulator();
      break;
    case 't':
      create_circulator();
      return 0;
    }
  }
      
  predict_circulation();
}
