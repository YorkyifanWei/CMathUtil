#include <stdio.h>
#include <stdlib.h>
/* input a matrix */
void matrix_input(float **arr, int row, int column)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            scanf("%f", &arr[i][j]);
}
/* output a matrix */
void matrix_output(float **arr, int row, int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] >= 0)
                printf(" ");
            if (arr[i][j] > -10 && arr[i][j] < 10)
                printf(" ");
            printf("%.3f", arr[i][j]);
            (j == column - 1) ? printf("\n") : printf("\t");
        }
}
/* turn small numbers into 0.0 */
void clear_matrix(float **arr, int row, int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            /*
            if the element is too small, turn it into 0.0
            (to ensure that the elements are all float type)
            */
            if (arr[i][j] < 1e-6 && arr[i][j] > -1e-6)
                arr[i][j] = 0;
}
/*
copy **copy and paste it into **paste
just in the first 'row' lines and the first 'column' columns
*/
void matrix_copy(float **paste, float **copy, int row, int column)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            paste[i][j] = copy[i][j];
}
/* to add two matrices */
void matrix_addition(float **arr, float **arr_1, float **arr_2, int row, int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            arr[i][j] = arr_1[i][j] + arr_2[i][j];
}
/*
to assign the scalar multiplication of arr to arr_lambda
the two matrices can be equal
*/
void matrix_scalar_multiplication(float **arr_lambda, float **arr, int row, int column, float lambda)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            arr_lambda[i][j] = arr[i][j] * lambda;
}
/*
to multiple two matrices
arr: to store the answer; arr_1 & arr_2: the two matrixes to multiple
row: the row of arr_1; medium: the column of arr_1 & the row of arr_2; column: the column of arr_2
Notice: the three matrices must be pairwise unequal
*/
void matrix_multiplication(float **arr, float **arr_1, float **arr_2, int row, int medium, int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
        {
            arr[i][j] = 0;
            for (int k = 0; k < medium; k++)
                arr[i][j] += arr_1[i][k] * arr_2[k][j]; // cij = (1<=k<=medium)sigma(aik*bkj)
        }
}
/*
to calculate the transpose of a matrix (too slow, not recommend)
Notice: the two matrices must be unequal
*/
void matrix_transpose(float **arr_t, float **arr, int row, int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            arr_t[j][i] = arr[i][j];
}
/* to place the two matrices horizontally side by side */
void matrix_augmentation_h(float **arr, float **arr_l, float **arr_r, int row, int column_l, int column_r)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column_l; j++)
            arr[i][j] = arr_l[i][j];
        for (j = 0; j < column_r; j++)
            arr[i][j + column_l] = arr_r[i][j];
    }
}
/* to place the two matrices vertically side by side */
void matrix_augmentation_v(float **arr, float **arr_u, float **arr_d, int row_u, int row_d, int column)
{
    int i, j;
    for (i = 0; i < row_u; i++)
        for (j = 0; j < column; j++)
            arr[i][j] = arr_u[i][j];
    for (i = 0; i < row_d; i++)
        for (j = 0; j < column; j++)
            arr[i + row_u][j] = arr_d[i][j];
}
/* separate arr into two matrices horizontally */
void matrix_augmentation_h_reverse(float **arr, float **arr_l, float **arr_r, int row, int column_l, int column_r)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column_l; j++)
            arr_l[i][j] = arr[i][j];
        for (j = 0; j < column_r; j++)
            arr_r[i][j] = arr[i][j + column_l];
    }
}
/* separate arr into two matrices vertically */
void matrix_augmentation_v_reverse(float **arr, float **arr_u, float **arr_d, int row_u, int row_d, int column)
{
    int i, j;
    for (i = 0; i < row_u; i++)
        for (j = 0; j < column; j++)
            arr_u[i][j] = arr[i][j];
    for (i = 0; i < row_d; i++)
        for (j = 0; j < column; j++)
            arr_d[i][j] = arr[i + row_u][j];
}
/*
exchange line i and line j of the matrix,
line number start from 0
*/
void build_commutation_matrix_r(float **arr, int n, int i, int j)
{
    for (int k = 0; k < n; k++)
        for (int l = 0; l < n; l++)
            arr[k][l] = (k == l);
    arr[i][i] = arr[j][j] = 0;
    arr[i][j] = arr[j][i] = 1;
}
/*
multiple line i by lambda,
line number start from 0
*/
void build_vector_multiplication_matrix_r(float **arr, int n, int i, float lambda)
{
    for (int k = 0; k < n; k++)
        for (int l = 0; l < n; l++)
            arr[k][l] = (k == l);
    arr[i][i] = lambda;
}
/*
multiple line j and add it into line i,
line number start from 0
*/
void build_multi_add_matrix_r(float **arr, int n, int i, int j, float lambda)
{
    for (int k = 0; k < n; k++)
        for (int l = 0; l < n; l++)
            arr[k][l] = (k == l);
    arr[i][j] = lambda;
}
/*
transform the matrix into an identity matrix
the matrix will be changed
*/
void build_identity_matrix(float **arr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
}
/*
to transport the matrix into row echelon form
the matrix will be changed
*/
void row_identity_echelon_form(float **arr, int row, int column)
{
    /* initialize variables */
    int i = 0, j = 0;
    int k;
    float **temp;
    temp = (float **)malloc(row * sizeof(float *));
    for (k = 0; k < row; k++)
        temp[k] = (float *)malloc(column * sizeof(float));
    float **elementary; // it is for those elementary matrices
    elementary = (float **)malloc(row * sizeof(float *));
    for (k = 0; k < row; k++)
        elementary[k] = (float *)malloc(row * sizeof(float));

    /* main part for elementary row transformation */
    while (i < row && j < column)
    {
        /* search for the line whose first number is not 0.0 */
        for (k = i; k < row; k++)
            if (arr[k][j] != 0) // as it is found, break the circulation
                break;
        /* if it is not found, search in the next column */
        if (k == row)
        {
            j++;
            continue;
        }
        /* if the line is not on the top, then build the elementary matrix to exchange it with the top line*/
        if (k != i)
        {
            build_commutation_matrix_r(elementary, row, i, k);
            matrix_multiplication(temp, elementary, arr, row, row, column);
            matrix_copy(arr, temp, row, column);
        }
        /* if hte first number of the line is not 1.0, multiply the line by lambda to transform it into 1.0 */
        if (arr[i][j] != 1)
        {
            build_vector_multiplication_matrix_r(elementary, row, i, 1 / arr[i][j]);
            matrix_multiplication(temp, elementary, arr, row, row, column);
            matrix_copy(arr, temp, row, column);
        }
        /* step the following rows */
        for (k = i + 1; k < row; k++)
            if (arr[k][j] != 0)
            {
                build_multi_add_matrix_r(elementary, row, k, i, -arr[k][j]);
                matrix_multiplication(temp, elementary, arr, row, row, column);
                matrix_copy(arr, temp, row, column);
            }
        i++;
        j++;
    }
    for (i = 0; i < row; i++)
    {
        free(temp[i]);
        free(elementary[i]);
    }
    free(temp);
    free(elementary);
}
/* to calculate the rank of arr */
int matrix_rank(float **arr, int row, int column)
{
    int i, j, rank;
    /* used to avoid arr being changed */
    float **echelon;
    echelon = (float **)malloc(row * sizeof(float *));
    for (i = 0; i < row; i++)
        echelon[i] = (float *)malloc(column * sizeof(float));
    matrix_copy(echelon, arr, row, column);
    row_identity_echelon_form(echelon, row, column);
    i = j = rank = 0;
    while (i < row && j < column)
    {
        if (echelon[i][j] == 0) // if this column of line i is 0, turn to the next column
            j++;
        else // the first nonzero number of the line is found, then turn to the next line
        {
            i++;
            rank++;
        }
    }
    for (i = 0; i < row; i++)
        free(echelon[i]);
    free(echelon);
    return rank;
}
/*
use Gauss Elimination to solve equation set
row & column are the line number & column number of the augmented matrix
int type means that { 1 : infinitely many sets of solutions,
0 : only one solution, -1 : no solution}
*/
int gaussian_elimination(float **arr, int row, int column)
{
    /* initialize variables */
    int i, j, k, l, rank, dof_1, count; // dof_1 means the degree of freedom + 1
    float **echelon;                    // echelon is to be the row echelon form of arr
    _Bool *is_free;                     // is_free is to mark if x_n is free

    /* initialize echelon */
    echelon = (float **)malloc(row * sizeof(float *));
    for (i = 0; i < row; i++)
        echelon[i] = (float *)malloc(column * sizeof(float));
    is_free = (_Bool *)malloc((column - 1) * sizeof(_Bool)); // the first column - 1 columns are in coefficient matrix part
    matrix_copy(echelon, arr, row, column);
    row_identity_echelon_form(echelon, row, column);

    /* initialize is_free */
    for (i = 0; i < column - 1; i++)
        is_free[i] = 1;
    i = j = rank = 0;
    while (i < row && j < column - 1)
    {
        if (echelon[i][j] == 0)
            j++;
        else
        {
            i++;
            rank++;
            is_free[j] = 0;
        }
    }

    /*
    if the last line only has constant term and it is not 0
    the system of linear equations has no solution
    */
    if (rank < row)
        if (arr[rank][column - 1] != 0)
        {
            for (i = 0; i < row; i++)
                free(echelon[i]);
            free(echelon);
            free(is_free);
            printf("This system of linear equations has no solution!\n");
            return -1; // break the function
        }

    dof_1 = column - rank; // dof_1 means the degree of freedom + 1

    /*
    if dof == 0(dof_1 == 1)
    the system of linear equations has and only has one solution
    */
    if (dof_1 == 1)
    {
        printf("This system of linear equations has only one solution\n");

        float **temp;       // a temp for matrix multiplication
        float **elementary; // elementary is for elementary row transformation
        /* initialize temp & elementary */
        temp = (float **)malloc(row * sizeof(float *));
        for (i = 0; i < row; i++)
            temp[i] = (float *)malloc(column * sizeof(float));
        elementary = (float **)malloc(row * sizeof(float *));
        for (i = 0; i < row; i++)
            elementary[i] = (float *)malloc(row * sizeof(float));

        for (i = rank - 1; i > 0; i--)
            for (j = i - 1; j >= 0; j--)
            {
                build_multi_add_matrix_r(elementary, row, j, i, -echelon[i][j]);
                matrix_multiplication(temp, elementary, echelon, row, row, column);
                matrix_copy(echelon, temp, row, column);
            }
        for (i = 0; i < rank; i++)
            printf("x%d = %.2f\n", i + 1, echelon[i][column - 1]);
        for (i = 0; i < row; i++)
        {
            free(echelon[i]);
            free(temp[i]);
            free(elementary[i]);
        }
        free(echelon);
        free(temp);
        free(elementary);
        free(is_free);
        return 0;
    }

    /*
    if dof > 0
    the system of linear equations has infinitely many sets of solutions
    */
    else if (dof_1 > 1)
    {
        printf("This system of linear equations has infinitely many sets of solutions\nThey're as follows:\n");

        _Bool flag;
        /* initialize coefficient */
        float **coefficient; // coefficient is the coefficient matrix of the answer
        coefficient = (float **)malloc((column - 1) * sizeof(float *));
        for (i = 0; i < column - 1; i++)
            coefficient[i] = (float *)malloc(dof_1 * sizeof(float));
        for (i = 0; i < column - 1; i++)
            for (j = 0; j < dof_1; j++)
                coefficient[i][j] = 0;

        /* edit coefficient */
        for (i = rank - 1, j = column - 2, count = dof_1 - 2; i >= 0 && j >= 0; j--)
        {
            if (is_free[j])
            {
                coefficient[j][count--] = 1;
                continue;
            }
            else
            {
                for (k = 0; k < column - 1; k++)
                    if (k != j)
                        for (l = 0; l < dof_1; l++)
                            coefficient[j][l] -= coefficient[k][l] * echelon[i][k];
                coefficient[j][dof_1 - 1] += echelon[i][column - 1];
                i--;
            }
        }

        /* print the solutions */
        for (i = 0; i < column - 1; i++)
        {
            printf("x%d = ", i + 1);
            for (j = 0, flag = 0; j < dof_1 - 1; j++)
            {
                printf("\t");
                if (coefficient[i][j] == 0)
                    continue;
                if (coefficient[i][j] > 0)
                {
                    if (flag)
                        printf("+");
                    else
                        printf(" ");
                }
                printf("%.2ft%d", coefficient[i][j], j + 1);
                flag = 1;
            }
            if (coefficient[i][dof_1 - 1] == 0)
                printf("\n");
            else
            {
                printf("\t");
                if (coefficient[i][j] > 0)
                {
                    if (flag)
                        printf("+");
                    else
                        printf(" ");
                }
                printf("%.2f\n", coefficient[i][dof_1 - 1]);
            }
        }
        for (i = 0; i < row; i++)
            free(echelon[i]);
        free(echelon);
        for (i = 0; i < column - 1; i++)
            free(coefficient[i]);
        free(coefficient);
        free(is_free);
        return 1;
    }

    /* if dof_1 < 1, there must be something wrong */
    else
    {
        for (i = 0; i < row; i++)
            free(echelon[i]);
        free(echelon);
        free(is_free);
        printf("There must be something wrong in this program!");
        return 500;
    }
}
/* to calculate the value of a determinant */
float determinant(float **arr, int n)
{
    int i, j, k;
    float product;
    float **echelon;
    echelon = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++)
        echelon[i] = (float *)malloc(n * sizeof(float));
    matrix_copy(echelon, arr, n, n);
    float **temp;
    temp = (float **)malloc(n * sizeof(float *));
    for (k = 0; k < n; k++)
        temp[k] = (float *)malloc(n * sizeof(float));
    float **elementary; // it is for those elementary matrices
    elementary = (float **)malloc(n * sizeof(float *));
    for (k = 0; k < n; k++)
        elementary[k] = (float *)malloc(n * sizeof(float));

    /* main part for elementary row transformation */
    i = j = 0;
    while (i < n && j < n)
    {
        /* search for the line whose first number is not 0.0 */
        for (k = i; k < n; k++)
            if (echelon[k][j] != 0) // as it is found, break the circulation
                break;
        /* if it is not found, then break the function */
        if (k == n)//! if the whole column has not an nonzero number, that means the determinant is 0
            return 0;
        /* if the line is not on the top, then build the elementary matrix to exchange it with the top line*/
        if (k != i)
        {
            build_commutation_matrix_r(elementary, n, i, k);
            matrix_multiplication(temp, elementary, echelon, n, n, n);
            matrix_copy(echelon, temp, n, n);
        }
        /* step the following rows */
        for (k = i + 1; k < n; k++)
            if (echelon[k][j] != 0)
            {
                build_multi_add_matrix_r(elementary, n, k, i, -echelon[k][j] / echelon[i][j]);
                matrix_multiplication(temp, elementary, echelon, n, n, n);
                clear_matrix(temp, n, n);
                matrix_copy(echelon, temp, n, n);
            }
        i++;
        j++;
    }
    for (i = 0, product = 1; i < n; i++)
        product *= echelon[i][i];
    for (i = 0; i < n; i++)
    {
        free(echelon[i]);
        free(temp[i]);
        free(elementary[i]);
    }
    free(echelon);
    free(temp);
    free(elementary);
    return product;
}
/*
to assign the inverse of arr to inv
int type means that { 1 : the matrix is invertible, 0 : irreversible}
*/
int matrix_inverse(float **inv, float **arr, int n)
{
    if (matrix_rank(arr, n, n) != n)
        return 0;

    /* initialize values */
    int i, j;
    float **aug;
    float **elementary;
    float **temp;
    aug = (float **)malloc(n * sizeof(float *));
    elementary = (float **)malloc(n * sizeof(float *));
    temp = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++)
    {
        aug[i] = (float *)malloc(2 * n * sizeof(float));
        elementary[i] = (float *)malloc(n * sizeof(float));
        temp[i] = (float *)malloc(2 * n * sizeof(float));
    }

    /* initialize the augmentation matrix */
    build_identity_matrix(inv, n);
    matrix_augmentation_h(aug, arr, inv, n, n, n);
    row_identity_echelon_form(aug, n, 2 * n);

    /* transform arr into identity matrix(in the augmentation matrix) */
    for (i = n - 1; i > 0; i--)
        for (j = i - 1; j >= 0; j--)
        {
            build_multi_add_matrix_r(elementary, n, j, i, -aug[j][i]);
            matrix_multiplication(temp, elementary, aug, n, n, 2 * n);
            matrix_copy(aug, temp, n, 2 * n);
        }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            inv[i][j] = aug[i][j + n];
    for (i = 0; i < n; i++)
    {
        free(aug[i]);
        free(elementary[i]);
        free(temp[i]);
    }
    free(aug);
    free(elementary);
    free(temp);
    return 1;
}