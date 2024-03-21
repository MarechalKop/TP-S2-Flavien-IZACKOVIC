#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <numeric>   




int main() {

    // Question 1
    std::vector<int> vecZC {};
    for (int i = 0; i < 100; i++)
    {
         vecZC.push_back(rand()%100);
    }

    // Question 2
    std::vector<int>::iterator begin_iterator { vecZC.begin() };
    std::vector<int>::iterator end_iterator { vecZC.end() };
    

    for ( begin_iterator; begin_iterator != end_iterator;++ begin_iterator) 
    {
    std::cout << *begin_iterator << ", ";
    }
    std::cout<<std::endl;


    // Question 3
    int guess {};
    std::cout <<"Choisis un nombre entre 1 et 100, je vais t'indiquer s'il est dans mon tableau Ha ha HAAAA : ";
    std::cin >> guess;
    std::cout << std::endl;

    std::vector<int>::iterator find {std::find(vecZC.begin(),vecZC.end(),guess)};
    if (find !=vecZC.end())
    {
        std::cout << "Le nombre " << *find << " est bien dans le tableau" << std::endl;
    }
    else
    {
        std::cout <<"Ton nombre n'est pas dans le tableau" <<std::endl;
    }

    // Question 4 
    int guess2 {};
    std::cout <<"Choisis un nombre entre 1 et 100, je vais t'indiquer le nombre de fois qu'il apparait dans le tableau HeheHeHe : ";
    std::cin >> guess2;
    std::cout << std::endl;

    const int num_items = std::count(vecZC.cbegin(), vecZC.cend(), guess2);
    std::cout << "Ton nombre apparait " << num_items << " fois" << std::endl;


    // Question 5 
    std::cout << "Trions le tableau" << std::endl;
    std::sort(vecZC.begin(),vecZC.end());

    std::cout << "Waw ! C'est trie" << std::endl;
    for (int i {}; i < vecZC.size(); i++)
    {
        std::cout << vecZC[i] << ", ";
    }

    // Question 6
    std::cout << "Faisons maintenant la somme de tous les elements du tableau, ça doit etre dans mes cordes"  << std::endl;
    int init = 0;
    int somme = std::accumulate (vecZC.begin(), vecZC.end(), init);
    std::cout << "Abracadabra ! La somme est egale a " << somme << std::endl;
    
   








}

