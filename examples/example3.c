#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ea-roots.h"

/* Polynomial with a multiple root plus seveal simpler roots: the roots are
 * the roots of the unity of order 98 and 0.5; the expected accuracy on the
 * double root is ~ 8 digits, 16 on the others. */

int main(int argc, const char * argv)
{
  int degree = 100, j, ret;
  double complex *p = NULL;
  double complex *roots = NULL;

  p = malloc(sizeof(double complex) * (degree + 1));
  roots = malloc(sizeof(double complex) * degree);

  for (j = 3; j < degree-2; j++)
    p[j] = 0.0;

  p[0] = -0.25;
  p[1] = 1.0;
  p[2] = -1.0;

  p[degree-2] = 0.25;
  p[degree-1] = -1.0;
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
