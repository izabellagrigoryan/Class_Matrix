// Class_Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Matrix {
  
    int size1;
    int size2;
    int** arr;
public:
    Matrix(int size1, int size2)
    {
        this->size1 = size1;
        this->size2 = size2;
        arr = new int*[size1];
        for (int i = 0; i < size1; i++)
            arr[i] = new int[size2];

        randMatrix();
    }

    Matrix(const Matrix& matrix)
    {
        size1 = matrix.size1;
        size2 = matrix.size2;
        this->arr = new int* [size1];
        for (int i = 0; i < size1; i++)
            this->arr[i] = new int[size2];

        for (int i = 0; i < size1; i++)
            for(int j = 0; j < size2; j++)
                this->arr[i][j] = matrix.arr[i][j];
    }

    Matrix& operator=(const Matrix& matrix)
    {
        if (this != &matrix)
        {
            
            for (int i = 0; i < size1; i++)
            {
                delete[] arr[i];
                arr[i] = nullptr;
            }
            delete[] arr;
            arr = nullptr;

            size1 = matrix.size1;
            size2 = matrix.size2;

            this->arr = new int* [size1];
            for (int i = 0; i < size1; i++)
                this->arr[i] = new int[size2];

            for (int i = 0; i < size1; i++)
                for (int j = 0; j < size2; j++)
                    this->arr[i][j] = matrix.arr[i][j];
        }
        return *this;
    }

    Matrix(Matrix&& matrix)
    {
        if (this != &matrix)
        {
            this->size1 = matrix.size1;
            this->size2 = matrix.size2;

            this->arr = matrix.arr;
            
            matrix.size1 = 0;
            matrix.size2 = 0;
            matrix.arr = nullptr;

            std::cout << "This is move constructor" << std::endl;
        }
    }

    Matrix& operator=(Matrix&& matrix)
    {
        if (this != &matrix)
        {
            for (int i = 0; i < size1; i++)
            {
                delete[] this->arr[i];
                this->arr[i] = nullptr;
            }
            delete[] this->arr;
            this->arr = nullptr;

            this->size1 = matrix.size1;
            this->size2 = matrix.size2;

            this->arr = new int* [size1];
            for (int i = 0; i < size1; i++)
                this->arr[i] = new int[size2];

            for (int i = 0; i < size1; i++)
                for (int j = 0; j < size2; j++)
                    this->arr[i][j] = matrix.arr[i][j];

            for (int i = 0; i < size1; i++)
            {
                delete[] matrix.arr[i];
                matrix.arr[i] = nullptr;
            }
            delete[] matrix.arr;
            matrix.arr = nullptr;
            matrix.size1 = 0;
            matrix.size2 = 0;

            std::cout << "This is move assignment" << std::endl;
        }
        return *this;
    }

    void randMatrix()
    {
        for (int i = 0; i < size1; i++)
            for (int j = 0; j < size2; j++)
                arr[i][j] = rand() % 100 + 0;
    }

    void printMatrix()
    {
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
                std::cout << arr[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void swapColumns()
    {
        int p;
        for (int i = 0; i < size1; i++)
        {
            p = arr[i][0];
            arr[i][0] = arr[i][2];
            arr[i][2] = p;
        }
        printMatrix();
    }

    void swapRows()
    {
        int p;
        for (int i = 0; i < size2; i++)
        {
            p = arr[0][i];
            arr[0][i] = arr[2][i];
            arr[2][i] = p;
        }
        printMatrix();
    }

    ~Matrix()
    {
        for (int i = 0; i < size1; i++)
        {
            delete[] this->arr[i];
            this->arr[i] = nullptr;
        }
        delete[] this->arr;
        this->arr = nullptr;

    }
};
int main()
{
    Matrix myMatrix(4, 5);
    myMatrix.printMatrix();
    myMatrix.swapColumns();
    myMatrix.swapRows();

    Matrix my_second_matrix = myMatrix;
    my_second_matrix.printMatrix();

    Matrix my_third_matrix(2, 3);
    my_third_matrix.printMatrix();
    my_third_matrix = my_second_matrix;
    my_third_matrix.printMatrix();

    Matrix matrix1 = Matrix(3, 3);
    Matrix matrix2(std::move(matrix1));

    matrix2 = std::move(my_second_matrix);

    matrix2.printMatrix();
    my_second_matrix.printMatrix();
}

