#include <stdio.h>
#include <stdlib.h>

// Function to read a matrix
void readMatrix(int ***matrix, int rows, int cols) {
    *matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", *(*matrix + i) + j);
        }
    }
}

// Function to compute the product of two matrices
void multiplyMatrices(int **mat1, int **mat2, int ***result, int rows1, int cols1, int cols2) {
    *result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        (*result)[i] = (int *)malloc(cols2 * sizeof(int));
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            *(*(*result + i) + j) = 0;
            for (int k = 0; k < cols1; k++) {
                *(*(*result + i) + j) += *(*(mat1 + i) + k) * *(*(mat2 + k) + j);
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int cols) {
    printf("The resultant matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int **mat1, **mat2, **result;
    int rows1, cols1, rows2, cols2;

    printf("Enter dimensions of first matrix (rows and columns): ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter dimensions of second matrix (rows and columns): ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible with these dimensions.\n");
        return 1;
    }

    readMatrix(&mat1, rows1, cols1);
    readMatrix(&mat2, rows2, cols2);

    multiplyMatrices(mat1, mat2, &result, rows1, cols1, cols2);

    displayMatrix(result, rows1, cols2);

    // Free allocated memory
    for (int i = 0; i < rows1; i++) {
        free(mat1[i]);
    }
    free(mat1);

    for (int i = 0; i < rows2; i++) {
        free(mat2[i]);
    }
    free(mat2);

    for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}