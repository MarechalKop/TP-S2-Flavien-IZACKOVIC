#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = ";
    std:: cout << f1 << std::endl;
    // f1.display();
    std::cout << "f2 = ";
    std:: cout << f2 << std::endl;
    // f2.display();
    std::cout << std::endl;

    Fraction f3 { f1 + f2 };

    std::cout << "f1 + f2 = ";
    std:: cout << f3 << std::endl;
    // f3.display();

    std::cout << std::endl << "f1 - f2 = ";
    std:: cout << (f1-f2) << std::endl;
    // (f1 - f2).display();

    std::cout << std::endl << "f1 * f2  = ";
    std:: cout << (f1*f2) << std::endl;
    // (f1 * f2).display();

    std::cout << std::endl << "f1 / f2  = ";
    std:: cout << (f1/f2) << std::endl;
    // (f1 / f2).display();

    std::cout << "f1 et f2 sont egaux : " << (f1 == f2) << std::endl;
    std::cout << "f1 < f2 ? " << (f1 < f2) << std::endl;
    std::cout << "f1 <= f2 ? " << (f1 <= f2) << std::endl;
    std::cout << "f1 > f2 ? " << (f1 > f2) << std::endl;
    std::cout << "f1 >= f2 ? " << (f1 >= f2) << std::endl;
    float d1 {static_cast<float>(f1)};
     std::cout << "f1 / f2 en decimal = " << (d1) << std::endl;
    
    return 0;
}