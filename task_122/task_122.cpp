#include <iostream>
#include <fstream>
#include "Random.h"

int main()
{
    write();

    int quantity;

    std::ifstream input("input.txt");
    input >> quantity;

    int *Values = new int[quantity];

    for (int i = 0; i < quantity; ++i) {
        input >> Values[i];
    }

    input.close();

    int lenMax = 0;
    int temp = 1;
    
    for (int i = 1; i < quantity; ++i) {
        if (Values[i-1] < Values[i]) {
            std::cout << Values[i - 1] << " " << Values[i] << std::endl;
            temp++;
        }
        else {
            if (lenMax < temp) {
                lenMax = temp;
            }
            temp = 1;
        }
    }
    delete[] Values;

    std::ofstream output("output.txt");
    output << lenMax;

    output.close();
}

