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
    iter(arr, 4, printChar);  // Fonction en const ref
    std::cout << '\n';

    iter(arr, 4, toUpperChar);  // Fonction en ref modifiable

    std::cout << "Après  : ";
    iter(arr, 4, printChar);  // Toujours valide
    std::cout << '\n';

    return 0;
}