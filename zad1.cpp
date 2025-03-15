#include <iostream>
#include <cmath>

int Armstrong(int Liczba)
{
    int Pomocnicza = Liczba;
    int sum = 0;
    int digits = 0;

    while (Pomocnicza != 0) {
        Pomocnicza /= 10;
        digits++;
    }

    Pomocnicza = Liczba;

    while(Pomocnicza > 0)
    {
        sum += std::pow((Pomocnicza % 10), digits);
        Pomocnicza /= 10;
    }
    return sum == Liczba ? 1 : 0;
}

int main()
{
    std::cout<<Armstrong(153);
    return 0;
}