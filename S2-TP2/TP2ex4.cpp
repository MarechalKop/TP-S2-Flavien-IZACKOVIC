#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#include "ScopedTimer.hpp"

int search (std::vector<int> & croissant, int valeur)
    {   
        int left = 0;
        int right = croissant.size() - 1;
        int middle = (left + right)/2;
        while (middle != valeur)
            {
                middle = (left + right)/2;
                if (left > right)
                {
                    middle = -1;
                    break;
                }
                else if (croissant[middle] < valeur) 
                    {
                        left = middle + 1;
                    }
                else if (croissant[middle] > valeur)
                    {
                        right = middle - 1;
                    }
                else if (croissant[middle] = valeur)
                    {
                        break;
                    }
              
            }
        return middle;
    }

int main () {
    std::vector<int> croissant1 = {1, 2, 2, 3, 4, 8, 12};
    int valeur1 = 8;
    std::cout << "L'indice de " << valeur1 << " dans le tableau [1, 2, 2, 3, 4, 8, 12] est " << search(croissant1,valeur1)<< std::endl;

    std::vector<int> croissant2 = {1, 2, 3, 3, 6, 14, 12, 15};
    int valeur2 = 15;
    std::cout << "L'indice de " << valeur2 << " dans le tableau [1, 2, 3, 3, 6, 14, 12, 15] est " << search(croissant2,valeur2)<<std::endl;

    std::vector<int> croissant3 = {2, 2, 3, 4, 5, 8, 12, 15, 16};
    int valeur3 = 16;
    std::cout << "L'indice de " << valeur3 << " dans le tableau [2, 2, 3, 4, 5, 8, 12, 15, 16] est " << search(croissant3,valeur3)<<std::endl;

    std::vector<int> croissant4 = {5, 6, 7, 8, 9, 10, 11, 12, 13};
    int valeur4 = 6;
    std::cout << "L'indice de " << valeur4 << " dans le tableau [5, 6, 7, 8, 9, 10, 11, 12, 13] est " << search(croissant4,valeur4)<<std::endl;

    std::vector<int> croissant5 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int valeur5 = 10;
    std::cout << "L'indice de " << valeur5 << " dans le tableau [5, 6, 7, 8, 9, 10, 11, 12, 13] est " << search(croissant5,valeur5)<<std::endl;
}