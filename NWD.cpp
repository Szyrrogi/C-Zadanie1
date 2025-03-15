#include <iostream>
#include <chrono>

int nwdI(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int nwd(int a, int b) {
    if (b == 0) return a;
    return nwd(b, a % b);
}


int main() {
    int a, b;
    std::cout << "Podaj dwie liczby: ";
    std::cin >> a >> b;

     auto startL = std::chrono::high_resolution_clock::now();
     int wynikL = nwdI(a, b);
     auto endL = std::chrono::high_resolution_clock::now();
     std::chrono::duration<double> elapsedL = endL - startL;
 
     auto startR = std::chrono::high_resolution_clock::now();
     int wynikR = nwd(a, b);
     auto endR = std::chrono::high_resolution_clock::now();
     std::chrono::duration<double> elapsedR = endR - startR;
 
     std::cout << "NWD (iteracyjnie): " << wynikL << " Czas: " << elapsedL.count() << " sekund" << std::endl;
     std::cout << "NWD (rekurencyjnie): " << wynikR << " Czas: " << elapsedR.count() << " sekund" << std::endl;
     std::cout << "Szybszy: " << (elapsedL.count() < elapsedR.count() ? "iteracyjny" : "rekurencyjny") << std::endl;
    return 0;
}