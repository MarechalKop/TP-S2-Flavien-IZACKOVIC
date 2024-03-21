#include <string>
#include <algorithm>
#include <iostream>

bool estPalindrome(const std::string& s) {
    return std::equal(s.begin(), s.end(), s.rbegin());
}

void display (int nombre){
    if (nombre == 1)
    {
        std::cout << "C'est bien un palidrome, gg" << std::endl;
    }
    else if (nombre == 0)
    {
        std::cout << "Mec c'est quoi ce mot ? C'est meme pas un palidrome" << std::endl;
    }
}

int main() {
std::string mot {};
std::cout << "Donne moi un mot, je vais te dire si c'est un palidrome" << std::endl;
std::cin >> mot;
std::cout << std::endl;

bool reponsePalin {};
reponsePalin = estPalindrome(mot);

display(reponsePalin);
}