#include "math type define.h"
#define max(a,b) ((a) > (b)) ? (a) : (b)
#define min(a,b) ((a) > (b)) ? (b) : (a)
N_set sigmaN(N_set *arr, Length len);// to sum up all elements in a natural array
N_set powerN(N_set base, N_set pow);// the nth power of a natural number
N_set factorialN(N_set n);// the factorial of a natural number

Z_set sigmaZ(Z_set *arr, Length len);// to sum up all elements in a integer array
Z_set absZ(Z_set n);// the absolute value of a integer number

R_set sigmaR(R_set *arr, Length len);// to sum up all elements in a real array
R_set powerR(R_set base, N_set pow);// the nth power of a real number
R_set absR(R_set a);// the absolute value of a real number
R_set rootR(R_set a, N_set n);// the nth root of a real number
