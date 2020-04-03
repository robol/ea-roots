/*
 * Ehrlich-Aberth based polynomial solver.
 *
 */

#include <complex.h>

/**
 * @brief Compute the roots of a polynomial with complex coefficients.
 *
 * @param p Vector containing the coefficients of the polynomial, ordered
 *          by degree: p[0] is the constant term, where p[degree] is the
 *          leading coefficient.
 *
 * @param degree Degree of the polynomial.
 * @param roots A complex double array of length degree, where the approximated
 *              roots will be stored.
 *
 * @return 0 if all the roots were computed. Otherwise, a positive integer
 *           indicating the number of non approximated components is returned.
 */
int ea_roots(const double complex * p, int degree, double complex * roots);
