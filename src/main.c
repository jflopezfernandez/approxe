
#include "approxe.h"

#define ABS(x) ((x < 0) ? -(x) : (x))

#define E 2.718281828459045

double calculate_percent_error(double empirical_value) {
    return (ABS(empirical_value - E) / E) * 100;
}

int main(int argc, char *argv[])
{
    /** Use the last argument from the command line as the number of
     *  approximations to calculate.
     * 
     */
    int n = (argc == 1) ? 10 : atoi(argv[argc - 1]);

    double e = 0.0;
    double a = 0.0;
    double b = 1.0; // This number is used to hold a running sum of n factorial.

    for (int i = 0; i < n; ++i) {
        /** Since we're approximating the value of the Euler constant using a
         *  Taylor series, the value of 'x' in the equation is going to be 1. In
         *  C, the 'pow' function expects a double-precision floating point
         *  number.
         * 
         */
        a = pow(1.0, i);
        b = (i == 0) ? 1 : b * i;
        
        e += a / b;
    }

    printf("n: %d\n", n);
    printf("e = %lf\n", e);
    printf("error: %lf\n", calculate_percent_error(e));

    return EXIT_SUCCESS;
}

