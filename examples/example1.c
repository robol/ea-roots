#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ea-roots.h"

/* x^n - 1 for n = 150 */

int main(int argc, const char * argv)
{
  int degree = 150, j, ret;
  double complex *p = NULL;
  double complex *roots = NULL;

  p = malloc(sizeof(double complex) * (degree + 1));
  roots = malloc(sizeof(double complex) * degree);

  /* x^degree - 10.0 */
  for (j = 1; j < degree; j++)
    p[j] = 0.0;
  
  p[0] = -10.0;
  p[degree] = 1.0;

  ret = ea_roots(p, degree, roots);

  printf("Return code: %d\n", ret);

  for (j = 0; j < degree; j++)
    {
      printf("Root[%d]: %3.16f + %3.16f I\n", j, creal(roots[j]), cimag(roots[j]));
    }

  free(roots);
  free(p);
}
