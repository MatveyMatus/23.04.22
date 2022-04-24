#include <iostream>
#include <fstream>
#include "matrix.h"

int main()
{
    int size;
            
    std::ifstream Values("input.txt");
    Values >> size;

    int** Matrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        Matrix[i] = new int [size];
    }

    int** MatrixSum = new int* [size];
    for (int i = 0; i < size; ++i) {
        MatrixSum[i] = new int[size];
    }

    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j) {
            Values >> Matrix[i][j];
        }
    }
    Values.close();

    int sum = 0;
    MatrixSum[0][0] = Matrix[0][0];
    for (int i = 0; i < size; ++i) {
        sum += Matrix[i][0];
        MatrixSum[i][0] = sum;
    }

    sum = 0;
    for (int j = 0; j < size; ++j) {
        sum += Matrix[0][j];
        MatrixSum[0][j] = sum;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << MatrixSum[i][j] << " ";
        }
        std::cout << std::endl;
    }


    std::cout << std::endl;

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size-1; ++j) {
            if (MatrixSum[i][j] < MatrixSum[i - 1][j+1]) {
                MatrixSum[i][j + 1] = Matrix[i][j + 1] + MatrixSum[i][j];
            }
            else {
                MatrixSum[i][j + 1] = Matrix[i][j + 1] + MatrixSum[i - 1][j + 1];
            }
        }       
    }

    printArray(MatrixSum, size);
    printArray(Matrix, size);
    
    Matrix[0][0] = -1;
    Matrix[size-1][size-1] = -1;

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size-1; ++j) {
            if (MatrixSum[i][j] < MatrixSum[i - 1][j + 1] && MatrixSum[i][j + 1] < MatrixSum[size - 1][size - 1]) {
                Matrix[i][j] = -1;
            }
            else {
                Matrix[i - 1][j + 1] = -1;
            }
        }
    }
    printArray(Matrix, size);
    
    std::ofstream motion("output.txt");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (Matrix[i][j] == -1) {
                motion << "* ";
            }
            else {
                motion << "# ";
            }
        }
       motion << std::endl;
    }
    motion.close();
    
    for (int i = 0; i < size; ++i) {
        delete[] Matrix[i];
    }
    delete[] Matrix;

    for (int i = 0; i < size; ++i) {
        delete[] MatrixSum[i];
    }
    delete[] MatrixSum;
}
