#include <iostream>
#include <fstream>
#include <ctime>
#include "matrix.h"

void printArray(int** Arr, int size) {
	std::cout << std::endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << Arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
