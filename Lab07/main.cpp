
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

const int SIZE = 4;           // Global variable for matrix size
const int MAX_FILENAME = 100; // Maximum filename length

class Matrix
{
private:
  int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin()
  {
    char filename[MAX_FILENAME];

    // get file name from user
    if (scanf("%s", filename) != 1)
    {
      printf("Error reading filename\n");
    }
    else
    {
      // open file
      FILE *file = fopen(filename, "r");
      // check for empty file
      if (file == NULL)
      {
        printf("Error: Unable to open file %s\n", filename);
      }
      else
      {
        // Read matrix data
        for (int i = 0; i < SIZE; i++)
        {
          for (int j = 0; j < SIZE; j++)
          {
            if (fscanf(file, "%d", &data[i][j]) != 1)
            {
              printf("Error: Not enough data in file or invalid format\n");
              fclose(file);
            }
          }
        }
      }
      fclose(file);
    }
  }

  // 2. Display a matrix
  void display() const
  {
    // loop for rows
    for (int i = 0; i < SIZE; i++)
    {
      // loop for columns
      for (int j = 0; j < SIZE; j++)
      {
        // print data out
        cout << setw(4) << data[i][j];
      }
      // end of each row
      cout << endl;
    }
    // end of matrix
    cout << endl;
  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix &other) const
  {
    // make empty result matrix
    Matrix result;

    // loop for rows
    for (int i = 0; i < SIZE; i++)
    {
      // loop for columns
      for (int j = 0; j < SIZE; j++)
      {
        // set result.data to 0
        result.data[i][j] = 0;
      }
    }

    // preform matrix addition
    // loop for rows
    for (int i = 0; i < SIZE; i++)
    {
      // loop for columns
      for (int j = 0; j < SIZE; j++)
      {
        // add
        result.data[i][j] = data[i][j] + other.data[i][j];
      }
    }
    return result;
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix &other) const
  {
    // make empty result matrix
    Matrix result;

    // loop for rows
    for (int i = 0; i < SIZE; i++)
    {
      // loop for columns
      for (int j = 0; j < SIZE; j++)
      {
        // set  result.data to 0s
        result.data[i][j] = 0;
      }
    }

    // preform matrix multiplication
    // loop for rows
    for (int i = 0; i < SIZE; i++)
    {
      // loop for columns
      for (int j = 0; j < SIZE; j++)
      {
        for (int k = 0; k < SIZE; k++)
        {
          result.data[i][j] += data[i][k] + other.data[k][j];
        }
      }
    }
    return result;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const
  {
    int sum = 0;
    // identity diagonal (top-left to bottom-right)
    for (int i = 0; i < SIZE; i++)
    {
      sum += data[i][i];
    }

    // second diagonal (bottom-left to top-right)
    for (int i = 0; i < SIZE; i++)
    {

      /*
      prevent adding center number twice
      matrices with  SIZE that is odd
      */
      if (i != SIZE - 1 - i)
      {
        sum += data[i][SIZE - 1 - i];
      }
    }

    return sum;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2)
  {
    //check if row1 and row2 are with in range
    if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE)
    {
      for (int j = 0; j < SIZE; j++)
      {
        //swap row1 and row2
        int temp = data[row1][j];
        data[row1][j] = data[row2][j];
        data[row2][j] = temp;
      }
    }
    else
    {
      cout << "Invalid row indices for swapping" << endl;
    }
  }
};

int main()
{
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
