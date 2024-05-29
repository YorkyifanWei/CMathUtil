void matrix_input(float **arr, int row, int column);// declare; input a matrix
void matrix_output(float **arr, int row, int column);// declare; output a matrix
void clear_matrix(float **arr, int row, int column);// turn small numbers into 0.0
void matrix_copy(float **paste, float **copy, int row, int column);// copy **copy and paste it into **paste
void matrix_addition(float **arr, float **arr_1, float **arr_2, int row, int column);// to add two matrices
void matrix_scalar_multiplication(float **arr_lambda, float **arr, int row, int column, float lambda);// to assign the scalar multiplication of arr to arr_lambda
void matrix_multiplication(float **arr, float **arr_1, float **arr_2, int row, int medium, int column);// to multiple two matrices
void matrix_transpose(float **arr_t, float **arr, int row, int column);// to calculate the transpose of a matrix
void matrix_augmentation_h(float **arr, float **arr_l, float **arr_r, int row, int column_l, int column_r);// place the two matrices horizontally side by side
void matrix_augmentation_v(float **arr, float **arr_u, float **arr_d, int row_u, int row_d, int column);// place the two matrices vertically side by side
void matrix_augmentation_h_reverse(float **arr, float **arr_l, float **arr_r, int row, int column_l, int column_r);// separate arr into two matrices horizontally
void matrix_augmentation_v_reverse(float **arr, float **arr_u, float **arr_d, int row_u, int row_d, int column);// separate arr into two matrices vertically
void build_commutation_matrix_r(float **arr, int n, int i, int j);// exchange line i and line j of the matrix
void build_vector_multiplication_matrix_r(float **arr, int n, int i, float lambda);// multiple line i by lambda
void build_multi_add_matrix_r(float **arr, int n, int i, int j, float lambda);// multiple line j and add it into line i
void build_identity_matrix(float **arr, int n);// transform the matrix into an identity matrix
void row_identity_echelon_form(float **arr, int row, int column);// to transport the matrix into row echelon form
int matrix_rank(float **arr, int row, int column);// to calculate the rank of a matrix
int gaussian_elimination(float **arr, int row, int column);// use Gauss Elimination to solve equation set
float determinant(float **arr, int n);// to calculate the value of a determinant
int matrix_inverse(float **inv, float **arr, int n);// to calculate the inverse of the matrix