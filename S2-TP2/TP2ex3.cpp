#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

void selection_sort(std::vector<int> & vec){
   int indiceMin {};

    for (int a = 0; a <= vec.size() - 1; a++ )
    {
        indiceMin = a;
         for (int i = a+1; i < vec.size(); i++)
        {
            if (vec[i] < vec[indiceMin])
                {
                    indiceMin = i;
                };
        }
    swap(vec[a], vec[indiceMin]);
    }
   
};






template<typename T>
size_t quick_sort_partition(std::vector<T> & vec, size_t left, size_t right);

void quick_sort(std::vector<int> & vec, size_t const left, size_t const right);

void quick_sort(std::vector<int> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

template<typename T>
size_t quick_sort_partition(std::vector<T> & vec, size_t left, size_t right) {
    int const pivot_value {vec[right]};
    size_t first_bigger_element_index { left };
    for (size_t i {left}; i < right ;i++) {
        if (vec[i]<pivot_value) {
            std::swap(vec[i], vec[first_bigger_element_index]);
            first_bigger_element_index += 1;
        }
    }
    std::swap(vec[first_bigger_element_index], vec[right]);
    return first_bigger_element_index;
}

void quick_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    if (left >= right) {
        return;
    };
    int indice_pivot = quick_sort_partition(vec,left, right);
    if (indice_pivot != 0) { // On vérifie que l'on ne sort pas du tableau par valeur inférieures 
        quick_sort(vec,left,indice_pivot-1);
    }
    if (indice_pivot + 1 < right) { // On vérifie que l'on ne sort pas du tableau par valeur supérieures
        quick_sort(vec,indice_pivot+1,right);
    }
}






int main () {

std::vector<int> vec = generate_random_vector (10,50);

{
    ScopedTimer timer("Chronomètre tri par selection");
    // code à chronométrer
    selection_sort(vec);
}
{
    ScopedTimer timer("Chronomètre tri rapide");
     // code à chronométrer
    quick_sort(vec);
}

{
    ScopedTimer timer("Chronomètre tri de la bibliothèque standart");
     // code à chronométrer
    std::sort(vec.begin(), vec.end());
}




}
