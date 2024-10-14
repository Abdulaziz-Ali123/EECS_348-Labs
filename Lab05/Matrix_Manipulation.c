#include <stdio.h>


#define SIZE 5

// print a matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    //loop through the rows
    for (int i = 0; i < SIZE; i++) {
        //loop through the columns
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// transpose a matrix
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    //loop through the rows of the array
    for (int i = 0; i < SIZE; i++) {
        //loop through the columns
        for (int j = 0; j < SIZE; j++) {
            // Swap rows with columns ie i and j
            result[j][i] = matrix[i][j]; 
        }
    }
}


// multiply two matrices
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    //loop through the rows 
    for (int i = 0; i < SIZE; i++) {
        //loop through the colums
        for (int j = 0; j < SIZE; j++) {
            // set result matrix element to 0 to avoid any random values that might have been initialized
            result[i][j] = 0;
            //loop through row for m1 and column for m2
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

//add matrices
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    //loop through the rows
    for (int i = 0; i < SIZE; i++) {
        //loop through the columns
        for (int j = 0; j < SIZE; j++) {
            //add together elemnts at i,j from m1 and m2 together
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}



int main() {
    //matrix 1
    int m1[SIZE][SIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };

    //matrix 2
    int m2[SIZE][SIZE] = {
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1}
    };

    //stores the restuling matrix
    int result[SIZE][SIZE];

    // Add matrices
    printf("Sum of m1 and m2:\n");
    addMatrices(m1, m2, result);
    //print matrix
    printMatrix(result);
    printf("\n");

    // Multiply matrices
    printf("Product of m1 and m2:\n");
    multiplyMatrices(m1, m2, result);
    //print matrix
    printMatrix(result);
    printf("\n");

    // Transpose matrix m1
    printf("Transpose of m1:\n");
    transposeMatrix(m1, result);
    //print matrix
    printMatrix(result);

}