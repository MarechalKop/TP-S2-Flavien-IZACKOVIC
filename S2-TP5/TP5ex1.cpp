#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <math.h>
#include <sstream>
#include <string>

// Question 1 ////////////////////////////////////////////////////////////
size_t folding_string_hash(std::string const& chainedentree, size_t max)
{
    size_t result {};
    for (int i {}; i < chainedentree.size(); i++)
    {
        result += chainedentree[i];
    }
    result = result%(max);
    return result;
};
////////////////////////////////////////////////////////////////////////

// Question 2 //////////////////////////////////////////////////////////
size_t folding_string_ordered_hash(std::string const& chainedentree, size_t max)
{
    size_t result {};
    for (int i {}; i < chainedentree.size(); i++)
    {
        result += chainedentree[i]*i;
    }
    result = result%(max);
    return result;
};
///////////////////////////////////////////////////////////////////////

// Question 3 /////////////////////////////////////////////////////////
size_t polynomial_rolling_hash(std::string const& chainedentree, size_t p, size_t m)
{
    size_t result {};
    size_t somme {};
    int power = 1;
    for (int i {}; i < chainedentree.size(); i++)
    {
        result = chainedentree[i]*power;
        somme += result%(m);
        power *= p;
    }
    return somme;
}
//////////////////////////////////////////////////////////////////////

int main() {
std::string chainedentree = {};
size_t max = {};
size_t p = {};

std::cout << "Ecris moi une phrase chacal : ";
std::getline(std::cin, chainedentree);
std::cout << std::endl; 

std::cout << "Maintenant donne moi un nombre maximum (s'il te plait) : ";
std::cin >> max;
std::cout << std::endl; 

std::cout << "Maintenant donne moi un nombre, tu as le choix, mais je voudrais un nombre premier comme 2 par exemple, je te dis ca mais c'est toi qui decide : ";
std::cin >> p;
std::cout << std::endl; 


std::cout << "le nombre renvoye par folding_string_hash est " << folding_string_hash(chainedentree, max) << std::endl;

std::cout << "le nombre renvoye par folding_string_ordered_hash est " << folding_string_ordered_hash(chainedentree, max) << std::endl;

std::cout << "le nombre renvoye par polynomial_rolling_hash est " << polynomial_rolling_hash(chainedentree,p, max) << std::endl;
}

