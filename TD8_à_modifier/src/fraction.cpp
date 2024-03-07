#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>



// void Fraction::display() {
//     std::cout << numerator << "/" << denominator;
// }



// Pour l'exercice 1

// Fraction operator+(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }


// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }


std::ostream& operator<<(std::ostream& os, Fraction const& F)
{
    return os << '(' << F.numerator << "/" << F.denominator << ')';
}

bool operator==(Fraction const& f1, Fraction const& f2){
   
    return f1.numerator * f2.denominator == f1.denominator * f2.numerator;
}

bool operator!=(Fraction const& f1, Fraction const& f2){
    return !(f1==f2);
}

bool operator<(Fraction const& f1, Fraction const& f2){
    return f1.numerator * f2.denominator < f1.denominator * f2.numerator;
}

bool operator<=(Fraction const& f1, Fraction const& f2){
    return (f1==f2) || (f1<f2);
}

bool operator>(Fraction const& f1, Fraction const& f2){
    return !(f1<f2);
}

bool operator>=(Fraction const& f1, Fraction const& f2){
    return !(f1<=f2);
}


Fraction Fraction::operator+=(Fraction const& f2) {
return simplify({
    this->numerator * f2.denominator + f2.numerator * this->denominator,
    this->denominator * f2.denominator
});
}

Fraction operator+(Fraction f1, Fraction const& f2){
    f1+=f2;
    return f1;
}




Fraction Fraction::operator-=(Fraction const& f2) {
return simplify({
    this->numerator * f2.denominator - f2.numerator * this->denominator,
    this->denominator * f2.denominator
});
}

Fraction operator-(Fraction f1, Fraction const& f2){
    f1-=f2;
    return f1;
}




Fraction Fraction::operator*=(Fraction const& f2) {
return simplify({
    this->numerator * f2.numerator,
    this->denominator * f2.denominator
});
}

Fraction operator*(Fraction f1, Fraction const& f2){
    f1*=f2;
    return f1;
}



Fraction Fraction::operator/=(Fraction const& f2) {
return simplify({
    this->numerator * f2.denominator,
    this->denominator * f2.numerator
});
}

Fraction operator/(Fraction f1, Fraction const& f2){
    f1/=f2;
    return f1;
}


