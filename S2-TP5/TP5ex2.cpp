#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes)
{
    std::unordered_map<std::string, std::vector<float>> map;
    for (int i = 0; i < robots_fixes.size(); i++){
        map[robots_fixes[i].first].push_back(robots_fixes[i].second);
    }   
    return map;
};

float sommeVectorDeFloat (std::vector<float> Vector)
{
    float somme {};
    for (int i {}; i < Vector.size(); i++)
    {
        somme += Vector[i];
    }

    return somme;
};

int main () 
{
    std::vector<std::pair<std::string, float>> fonctionRobotfixes = get_robots_fix(10);
    std::unordered_map<std::string, std::vector<float>> CreerTableauAssociatif = robots_fixes_map(fonctionRobotfixes);
    std::unordered_map<std::string, std::vector<float>>::iterator begin_iterator { CreerTableauAssociatif.begin() };
    std::unordered_map<std::string, std::vector<float>>::iterator end_iterator { CreerTableauAssociatif.end() };
    

    for ( begin_iterator; begin_iterator != end_iterator;++ begin_iterator) 
    {
         std::cout << "Le cout total des reparations du robot " << begin_iterator->first << " est " << sommeVectorDeFloat(begin_iterator->second) << " Dollars Americains (Hiha ! Cow-boy !)" << std::endl;
    }

}