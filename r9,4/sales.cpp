#include "sales.h"
#include <iostream>

void Sales::setSales(Sales & s, const double ar[], int n)
{
    double sum = 0;
    double min = ar[0];
    double max = ar[0];
    for (int i = 0; i < n; ++i)
    {
        if(min > ar[i])
            min = ar[i];
        if(max < ar[i])
        {
            std::cout << "tak" << std::endl;
            max = ar[i];
        }
        s.sales[i] = ar[i];
        sum += s.sales[i];
    }
    s.average = sum / n;
    s.min = min;
    s.max = max;
}

void Sales::setSales(Sales & s)
{
    std::cout << "Podaj sprzedaz dla " << QUARTERS << " sezonow: " << std::endl;
    double sum = 0;
    double min,max;
    min = max = 0;
    for (int i = 0; i < QUARTERS; ++i)
    {
        std::cout << "Sezon " << i+1 << ": ";
        while (!(std::cin >> s.sales[i]))
            std::cout << "Podaj liczbe: ";
        sum += s.sales[i];
        if (i == 0)
        {
            min = s.sales[i];
            max = s.sales[i];
        }
        else
        {
            if (min > s.sales[i])
                min = s.sales[i];
            if (max < s.sales[i])
                max = s.sales[i];
        }
    }
    std::cout << min;
    std::cout << max;
    s.min = min;
    s.max = max;
}

void Sales::showSales(const Sales & s)
{
    std::cout << "Sprzedaz: " << std::endl;
    for (int i = 0; i < QUARTERS; ++i)
    {
        std::cout <<"Sezon " << i+1 << ": " << s.sales[i] << std::endl;
    }
    std::cout.precision(2);
    std::cout << "Srednia: " << s.average << std::endl;
    std::cout << "Najmniejszy zysk: " << s.min << std::endl;
    std::cout << "Najwiekszy zysk: " << s.max << std::endl;
}