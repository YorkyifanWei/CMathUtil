#include "basic arithmetic.h"
#include <stdlib.h>
N_set sigmaN(N_set *arr, Length len)
{
    N_set sum = 0;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}
N_set powerN(N_set base, N_set pow)
{
    N_set antilogarithm = 1;
    for (int i = 0; i < pow; i++)
        antilogarithm *= base;
    return antilogarithm;
}
N_set factorialN(N_set n)
{
    N_set factorial = 1;
    for (int i = 1; i <= n; i++)
        factorial *= i;
    return factorial;
}

Z_set sigmaZ(Z_set *arr, Length len)
{
    Z_set sum = 0;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}
Z_set absZ(Z_set n)
{
    return (n > 0) ? n : -n;
}

R_set sigmaR(R_set *arr, Length len)
{
    R_set sum = 0;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}
R_set powerR(R_set base, N_set pow)
{
    R_set antilogarithm = 1;
    for (int i = 0; i < pow; i++)
        antilogarithm *= base;
    return antilogarithm;
}
R_set absR(R_set a)
{
    return (a > 0) ? a : -a;
}
R_set rootR(R_set a, N_set n)
{
    R_set x = 1.0;
    R_set y = 0.0;
    while (absR(x - y) > 1e-6)
    {
        y = x;
        x = a / (n * powerR(y, n - 1)) + ((n - 1) * y) / n;
    }
    return x;
}
