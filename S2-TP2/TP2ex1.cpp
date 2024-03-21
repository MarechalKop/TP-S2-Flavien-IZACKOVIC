#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }


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

    // La partie qui suit a pour but de renvoyer le tableau afin de suivre son évolution à chaque itération de la boucle



    // std::cout<< "{ ";
    // for (int i = 0; i < vec.size(); i++)
    // {   
    //     if (i < vec.size() - 1) {
    //     std::cout << vec[i]<< " , ";
    //     }
    //     else {  
    //     std::cout << vec[i]; 
    //     }
        
    // }
    //  std::cout << " }" << std::endl;
    // }
   
};


int main()
{
    std::vector<int> vec = {8,3,6,7,2,4,202,17};
    selection_sort(vec);

    if (is_sorted(vec)) {
    std::cout << "Le tableau est trie" << std::endl;
} else {
    std::cout << "Le tableau n'est pas trie" << std::endl;
}
}