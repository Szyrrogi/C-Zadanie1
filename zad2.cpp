#include <iostream>
#include <cmath>

bool isPerfectCube(int number) {
    int cubeRoot = round(cbrt(number));
    return cubeRoot * cubeRoot * cubeRoot == number && number >= 0;
}

int main() {
    int number;
    std::cout << "Podaj liczbe: ";
    std::cin >> number;

    if (isPerfectCube(number)) {
        std::cout << number << " jest szescianem." << std::endl;
    } else {
        std::cout << number << " nie jest szescianem." << std::endl;
    }

    return 0;
}
