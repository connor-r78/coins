#include "circulate.h"

int exitWithError(wchar_t *program) 
{
  PyMem_RawFree(program);
  Py_Finalize();
  return 1;
}

int setupCython(int argc, char** argv)
{
  PyObject *pmodule;
  wchar_t *program;

  program = Py_DecodeLocale(argv[0], NULL);
  if ( program == NULL ) {
    fprintf(stderr, "Fatal error: cannot decode argv[0], got %d arguments\n", argc);
    return 1;
  }

  if ( PyImport_AppendInittab("circulate", PyInit_circulate) == -1 ) {
    fprintf(stderr, "Error, could not extend in-built modules table\n");
    return 1; 
  }

  Py_Initialize();

  pmodule = PyImport_ImportModule("circulate");
  if ( !pmodule ) {
    PyErr_Print();
    fprintf(stderr, "Error: could not import module\n");
    return exitWithError(program);
  }

  return 0;
}
