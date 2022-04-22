#include <iostream>
#include <fstream>
#include <ctime>
#include "Random.h"

void write() {
	srand(time(NULL));
	int quantity = rand() % 20 + 1;

	std::ofstream RandomValue("input.txt");
	RandomValue << quantity << std::endl;

	for (int i = 0; i < quantity; ++i) {
		RandomValue << rand() % 999 + 1 << " ";
	}
	RandomValue.close();
}