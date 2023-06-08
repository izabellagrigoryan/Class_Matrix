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
            delete[] arr[i];
            arr[i] = nullptr;
        }
        delete[] arr;
        arr = nullptr;

    }
};
int main()
{
    Matrix myMatrix(4, 5);
    myMatrix.printMatrix();
    myMatrix.swapColumns();
    myMatrix.swapRows();

}

