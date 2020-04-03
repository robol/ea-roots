#include <complex.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

#define EA_ROOTS_PI 3.14159265358979
#define EA_ROOTS_DBL_EPSILON DBL_EPSILON

static double complex
ea_roots_newton (int n, const double complex * p, double complex z)
{
  int i;
  double eps;
  double complex pval, p1;

  eps = 4 * n * EA_ROOTS_DBL_EPSILON;

  /* Compute the evaluation of p and its derivative simultaneously. 
   * We distinguish the cases of z inside / outside of the unit circle
   * where we evaluate p(z) or p(1/z), for avoiding overflow / underflow
   * situations. */
  if (cabs(z) <= 1.0)
    {
      pval = p[n];
      p1 = pval;
  
      for (i = n - 1; i > 0; i--)
	{
	  pval = pval * z + p[i];
	  p1 = p1 * z + pval;	 
	}
  
      pval = pval * z + p[0];

      if (p1 == 0.0)
	{
	  p1 = 1.0;
	}
    
      return pval / p1;
    }
  else
    {
      double complex iz = 1.0 / z;
      
      pval = p[0];
      p1 = pval;
      
      for (i = n - 1; i > 0; i--)
        {
	  pval = pval * iz + p[n-i];
	  p1 = p1 * iz + pval;
        }
      pval = pval * iz + p[n];

      p1 = (n * pval - p1 * iz) * iz;

      if (p1 == 0.0)
	{
	  p1 = 1.0;
	}
      
      return pval / p1;
    }  
}

static double complex
ea_roots_aberth (int n, const double complex *roots, int i)
{
  double complex abcorr = 0.0;
  int j;

  for (j = 0; j < n; j++)
    {
      if (j != i)
	{
	  abcorr = abcorr + 1.0 / (roots[i] - roots[j]);
	}
    }

  return abcorr;
}

int ea_roots(const double complex * p, int degree, double complex * roots)
{
  int its, j;
  int maxits = 300;
  int converged_roots;
  double eps = EA_ROOTS_DBL_EPSILON;
  double complex nwt, abcorr;
  double shift = 0.0;

  /* Variable where the approximation status of the various
   * roots is kept. */
  char * status = malloc(sizeof(char) * degree);
  for (j = 0; j < degree; j++)
    status[j] = 0;

  /* Find initial approximations: the shift makes sure that the approximations will never
   * be real, which can cause convergence failures. */
  shift = EA_ROOTS_PI / degree;
  for (j = 0; j < degree; j++)
    {
      roots[j] = cos(shift + 2 * EA_ROOTS_PI * j / degree) +
	sin(shift + 2 * EA_ROOTS_PI * j / degree) * I;
    }

  maxits = 300;
  its = 0;
  converged_roots = 0;

  while (converged_roots < degree && its < maxits)
    {
      /* Perform an Aberth iteration over non-converged components */
      for (j = 0; j < degree; j++)
	{	  
	  if (status[j] == 0)
	    {
	      /* Compute Newton correction at the point */
	      nwt = ea_roots_newton(degree, p, roots[j]);

	      /* Compute Aberth's correction */
	      abcorr = ea_roots_aberth(degree, roots, j);

	      if (isnan(creal(abcorr)) || isnan(cimag(abcorr)))
		abcorr = nwt;
	      else
		abcorr = nwt / (1 - nwt * abcorr);

	      roots[j] = roots[j] - abcorr;

	      if (cabs(abcorr) < degree * eps * cabs(roots[j]) ||
		  cabs(nwt) < degree * eps * cabs(roots[j]))
		{
		  status[j] = 1;
		  converged_roots = converged_roots + 1;
		}
	    }
	}

      its++;
    }

  free (status);

  return (degree - converged_roots);
}

