#include <iostream>
#include <chrono>

int newtonI(int n, int k) {
    if (k > n - k) k = n - k;
    int result = 1;
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int newton(int n, int k) {
    if (k == 0 || k == n) return 1;
    return newton(n - 1, k - 1) + newton(n - 1, k);
}


int main() {
    int n, k;
    std::cout << "Podaj n i k: ";
    std::cin >> n >> k;

    auto startL = std::chrono::high_resolution_clock::now();
    int wynikL = newtonI(n, k);
    auto endL = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedL = endL - startL;

    auto startR = std::chrono::high_resolution_clock::now();
    int wynikR = newton(n, k);
    auto endR = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedR = endR - startR;
 
    std::cout << "Newton (iteracyjnie): " << wynikL << " Czas: " << elapsedL.count() << " sekund" << std::endl;
    std::cout << "Newton (rekurencyjnie): " << wynikR << " Czas: " << elapsedR.count() << " sekund" << std::endl;
    std::cout << "Szybszy: " << (elapsedL.count() < elapsedR.count() ? "iteracyjny" : "rekurencyjny") << std::endl;
    return 0;
}