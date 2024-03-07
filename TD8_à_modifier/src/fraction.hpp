#pragma once

#include <iostream>



struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    // void display();

    //Pour l'exercice 5

   Fraction operator+=(Fraction const& f2);
   Fraction operator-=(Fraction const& f2);
   Fraction operator*=(Fraction const& f2);
   Fraction operator/=(Fraction const& f2);

   
   operator float() const {
    return static_cast<float>(numerator) / denominator;
   }

};


std::ostream& operator<<(std::ostream& os, Fraction const& F); 

Fraction operator+(Fraction  f1, Fraction const& f2);
Fraction operator-(Fraction  f1, Fraction const& f2);
Fraction operator*(Fraction  f1, Fraction const& f2);
Fraction operator/(Fraction  f1, Fraction const& f2);
bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);

