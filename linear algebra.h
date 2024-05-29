#include "math type define.h"
#include <stdio.h>
#include <stdlib.h>
#define FreeMatrix(matrix) for(int i=0;i<matrix.row;i++)free(matrix.a[i]);free(matrix.a);
void buildMtxR(R_matrix matrix);
void mtxIOR(R_matrix matrix, const char ch);
void mtxCpyR(R_matrix paste, R_matrix copy);
void mtxAddR(R_matrix add, R_matrix left, R_matrix right);
void mtxSMulR(R_matrix matrix_lambda, R_matrix matrix, R_set lambda);
void mtxMulR(R_matrix mul, R_matrix left, R_matrix right);
void mtxTspR(R_matrix tran, R_matrix matrix);
R_matrix mtxAugR(R_matrix l_u, R_matrix r_d, const char ch);
