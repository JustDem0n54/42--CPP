#include "iter.hpp"
#include "string"
#include <iostream>
#include <cctype>


void printChar(const char& c) {
    std::cout << c << ' ';
}

void toUpperChar(char& c) {
    c = static_cast<char>(std::toupper(c));
}

int main() {
    char arr[] = {"abcd"};

    std::cout << "Avant : ";
    iter(arr, 4, printChar);  
    std::cout << '\n';

    iter(arr, 4, toUpperChar); 

    std::cout << "Après  : ";
    iter(arr, 4, printChar);  
    std::cout << '\n';

    return 0;
}