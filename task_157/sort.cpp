#include "sort.h"

int Fact(int n) {
	if (n == 0)
		return 1;
	else
		return n * Fact(n - 1);
}


void sort(std::string& str){
	for (int i = 0; i < str.length(); ++i) {
		for (int j = 0; j < str.length() - 1; ++j) {
			if (str[j] > str[j + 1]) {
				int temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
	}
}
