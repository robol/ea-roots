#include <ea-roots.h>

/*
 * This test computes the roots of the unity for different values of 
 * the degree, and checks that the returned results are accurate up
 * to the expected number of digits. 
 */

#include "common.h"
#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
check_nroots(int degree)
{
  int j, ret;
  double complex *p, *roots, *reference;

  /* We directly allocate the maximum possible degree */
  p = malloc(sizeof(double complex) * (degree + 1));
  roots = malloc(sizeof(double complex) * degree);
  reference = malloc(sizeof(double complex) * degree);

  memset(p + 1, 0, (degree-1) * sizeof(double complex));
  p[0] = -1.0; p[degree] = 1.0;
  
  ret = ea_roots(p, degree, roots);

  if (ret != 0)
    {
      fprintf(stderr,
	      "Error computing the roots of x^%d - 1: code %d\n",
	      degree, ret);

      return 1;
    }

  /* Build the reference approximations */
  for (j = 0; j < degree; j++)
    {
      reference[j] = cos(2.0 * j * EA_ROOTS_PI / degree) +
	sin(2.0 * j * EA_ROOTS_PI / degree) * I;
    }

  ret = check_roots(roots, reference, degree);

  if (ret != 0)
    {
      fprintf(stderr,
	      "Error computing the roots of x^%d - 1"
	      ": %d wrong approximations\n",
	      degree, ret);

      return 2;
    }  

  free(p);
  free(roots);
  free(reference);
}

int
main(int argc, const char* argv[])
{
  return check_nroots(4) ||
    check_nroots(10)     ||
    check_nroots(25)     ||
    check_nroots(100)    ||
    check_nroots(500);
}
