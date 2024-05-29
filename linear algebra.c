#include "linear algebra.h"
/* malloc for the real matrix */
void BuildMtxR(R_matrix matrix)
{
    matrix.a = (R_set **)malloc(matrix.row * sizeof(R_set *));
    for (int i = 0; i < matrix.row; i++)
        matrix.a[i] = (R_set *)malloc(matrix.col * sizeof(R_set));
}
/*
input or output a matrix
'i': input
'o': output
*/
void mtxIOR(R_matrix matrix, const char ch)
{
    switch (ch)
    {
        case 'i':
        {
            for (int i = 0; i < matrix.row; i++)
                for (int j = 0; j < matrix.col; j++)
                    scanf("%f", matrix.a[i] + j);
            break;
        }
        case 'o':
        {
            for (int i = 0; i < matrix.row; i++)
                for (int j = 0; j < matrix.col; j++)
                {
                    printf("%f", matrix.a[i][j]);
                    (j == matrix.col - 1) ? printf("\n") : printf(" ");
                }
            break;
        }
        default:
        {
            printf("In mtxIOR, you use the wrong character!\n");
            break;
        }
    }
}
/* copy copy and paste it into paste */
void mtxCpyR(R_matrix paste, R_matrix copy)
{
    if (paste.row != copy.row || paste.col != copy.col)
    {
        printf("In mtxCpyR, you use the wrong matrices!\n");
        return;
    }
    for (int i = 0; i < paste.row; i++)
        for (int j = 0; j < paste.col; j++)
            paste.a[i][j] = copy.a[i][j];
}
/* add up two matrices */
void mtxAddR(R_matrix add, R_matrix left, R_matrix right)
{
    if (add.row != left.row || add.row != right.row || add.col != left.col || add.col != right.col)
    {
        printf("In mtxAddR, you use the wrong matrices!\n");
        return;
    }
    for (int i = 0; i < add.row; i++)
        for (int j = 0; j < add.col; j++)
            add.a[i][j] = left.a[i][j] + right.a[i][j];
}
/*
to assign the scalar multiplication of arr to arr_lambda
the two matrices can be the same
*/
void mtxSMulR(R_matrix matrix_lambda, R_matrix matrix, R_set lambda)
{
    if (matrix_lambda.row != matrix.row || matrix_lambda.col != matrix.col)
    {
        printf("In mtxSMulR, you use the wrong matrices!\n");
        return;
    }
    for (int i = 0; i < matrix.row; i++)
        for (int j = 0; j < matrix.col; j++)
            matrix_lambda.a[i][j] = matrix.a[i][j] * lambda;
}
/*
to multiple two matrices
Notice: the three matrices must be pairwise unequal
*/
void mtxMulR(R_matrix mul, R_matrix left, R_matrix right)
{
    if (mul.row != left.row || left.col != right.row || mul.col != right.col)
    {
        printf("In mtxMUlR, you use the wrong matrices!\n");
        return;
    }
    for (int i = 0; i < mul.row; i++)
        for (int j = 0; j < mul.col; j++)
        {
            mul.a[i][j] = 0;
            for (int k = 0; k < left.col; k++)
                mul.a[i][j] += left.a[i][k] * right.a[k][j];
        }
}
/*
to calculate the transpose of a matrix
Notice: the two matrices must be unequal
*/
void mtxTspR(R_matrix tran, R_matrix matrix)
{
    if (tran.row != matrix.col || tran.col != matrix.row)
    {
        printf("In mtxTspR, you ues the wrong matrices!\n");
        return;
    }
    for (int i = 0; i < tran.row; i++)
        for (int j = 0; j < tran.col; j++)
            tran.a[i][j] = matrix.a[j][i];
}
/*
to place two matrices side by side
'v' means vertically
'h' means horizontally
*/
R_matrix mtxAugR(R_matrix l_u, R_matrix r_d, const char ch)
{
    switch (ch)
    {
        case 'v':
        {
            if (l_u.col != r_d.col)
            {
                printf("In mtxAugR, you use the wrong matrices!\n");
                break;
            }
            R_matrix matrix = {NULL, l_u.row + r_d.row, l_u.col};
            BuildMtxR(matrix);
            for (int i = 0; i < l_u.row; i++)
                for (int j = 0; j < l_u.col; j++)
                    matrix.a[i][j] = l_u.a[i][j];
            for (int i = 0; i < r_d.row; i++)
                for (int j = 0; j < r_d.col; j++)
                    matrix.a[i + l_u.row][j] = r_d.a[i][j];
            break;
        }
        case 'h':
        {
            if (l_u.row != r_d.row)
            {
                printf("In mtxAugR, you use the wrong matrices!\n");
                break;
            }
            R_matrix matrix = {NULL, l_u.row, l_u.col + r_d.col};
            BuildMtxR(matrix);
            for (int i = 0; i < matrix.row; i++)
            {
                int j;
                for (j = 0; j < l_u.col; j++)
                    matrix.a[i][j] = l_u.a[i][j];
                for (j = 0; j < r_d.col; j++)
                    matrix.a[i][j + l_u.col] = r_d.a[i][j];
            }
            break;
        }
        default:
        {
            printf("In mtxAugR, you use the wrong character!\n");
            break;
        }
    }
}