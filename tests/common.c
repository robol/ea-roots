#include <float.h>
#include <complex.h>

int
check_roots(double complex * roots, double complex * reference, int n)
{
  int i, j, counter = 0;

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++) {	
	if (cabs(roots[i] - reference[j]) < DBL_EPSILON * 4 * n)
	  {
	    counter++;
	    break;
	  }
      }
    }
  
  return (n - counter);
}
