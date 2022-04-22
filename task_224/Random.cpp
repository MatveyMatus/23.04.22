#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include "Random.h"

void write(){
	srand(time(NULL));
	std::ofstream RandomValue("input.txt");

	int quantity = rand() % 1000 + 3;

	RandomValue << quantity << std::endl;
	for (int i = 0; i < quantity; ++i) {
		RandomValue << rand() % 3000 - 1000 << " ";
	}
	RandomValue.close();
}

void sort(int arr[],int size){
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (abs(arr[j]) < abs(arr[j + 1])) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
