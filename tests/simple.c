#include <ea-roots.h>

/*
 * Test a few simple cases, such a degree 1 or degree 0 
 * polynomials to make sure that we handle corner cases
 * as well. 
 */

#include <complex.h>
#include <stdlib.h>
#include <float.h>
#include <stdio.h>

int
main(int argc, const char* argv[])
{
  /* Polynomials of degree 0 should have no roots, hence
   * we expect to never dereference the pointer to roots
   * in this case. */
  int ret;
  double complex p[] = { -1.0 * I, 2.0 };
  double complex root;

  ret = ea_roots(p, 0, NULL);

  if (ret != 0)
    {
      fprintf(stderr, "Failed to return with a polynomial of degree 0\n");
      return 1;
    }

  /* Check a degree 1 polynomial */
  ret = ea_roots(p, 1, &root);

  if (ret != 0)
    {
      fprintf(stderr, "Failed with a polynomial of degree 1\n");
      return 1;
    }

  /* Check the root */
  if (cabs(root - .5 * I) > 4 * DBL_EPSILON)
    {
      fprintf(stderr, "Failed to approximate the root of a polynomial of degree 1\n");
      fprintf(stderr, "Computed root: %e + %eI\n", creal(root), cimag(root));
      fprintf(stderr, "Expected root: -.5 I\n");
      return 1;
    }

  return 0;
}
