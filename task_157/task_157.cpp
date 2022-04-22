#include <iostream>
#include <fstream>
#include <string>
#include "sort.h"


int main()
{
    std::ifstream Value("input.txt");
    std::string word = "";
    Value >> word;
    Value.close();

    int MaxComb = Fact(word.length());
    sort(word);

    int repet = 1;
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == word[i + 1]) {
            repet++;
        }
    }
    
    std::ofstream result("output.txt");
    if (repet > 1) {
        result << MaxComb / Fact(repet);
    }
    else {
        result << MaxComb;
    }
    result.close();
}
