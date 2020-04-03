#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ea-roots.h"

/* Polynomial with a multiple root */

int main(int argc, const char * argv)
{
  int degree = 2, j, ret;
  double complex *p = NULL;
  double complex *roots = NULL;

  p = malloc(sizeof(double complex) * (degree + 1));
  roots = malloc(sizeof(double complex) * degree);

  p[0] = 1.0;
  p[1] = -2.0;
  p[2] = 1.0;

  ret = ea_roots(p, 2, roots);
  
  printf("Return code: %d\n", ret);

  for (j = 0; j < 2; j++)
    {
      printf("Root[%d]: %3.16f + %3.16f I\n", j, creal(roots[j]), cimag(roots[j]));
    }

  free(roots);
  free(p);
}
