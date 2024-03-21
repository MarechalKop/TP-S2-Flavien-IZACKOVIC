#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool is_sorted(std::vector<float> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

template<typename T>
size_t quick_sort_partition(std::vector<T> & vec, size_t left, size_t right);

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right);

void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

template<typename T>
size_t quick_sort_partition(std::vector<T> & vec, size_t left, size_t right) {
    T const pivot_value {vec[right]};
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

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    if (left >= right) {
        return;
    };
    int indice_pivot = quick_sort_partition(vec,left, right);
    quick_sort(vec,left,indice_pivot-1);
    quick_sort(vec,indice_pivot+1,right);
}

int main()
{
    std::vector<float> vec = {8,3,6,7,2,4,202,17};
    quick_sort(vec);

    if (is_sorted(vec)) {
    std::cout << "Le tableau est trie" << std::endl;
    } else {
    std::cout << "Le tableau n'est pas trie" << std::endl;
    }
}
