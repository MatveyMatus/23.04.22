#include <iostream>
#include <fstream>
#include "Random.h"

int main()
{
	write();

	int quantity;
	std::ifstream Values("input.txt");
	Values >> quantity;
	
	int* num = new int[quantity] {};

	for (int i = 0; i < quantity; ++i) {
		Values >> num[i];
	}
	Values.close();
	
	sort(num,quantity);
	
	int mult = 1;
	for (int i = 0; i < 3; ++i) {
		mult *= num[i];
	}

	std::ofstream result("output.txt");
	result << mult;
	result.close();

	delete[] num;
}

