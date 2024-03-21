#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <numeric>   
#include <sstream>
#include <string>


// Question 1 /////////////////////////////////////////////////////////////
auto const is_space = [](char letter){ return letter == ' '; };

int compteurDeLettre (std::string const & phrase){
    std::string::const_iterator premiereLettre = std::find_if_not (phrase.begin(),phrase.end(), is_space);
    std::string::const_iterator premiereEspace = std::find_if (premiereLettre,phrase.end(), is_space);
    int nombreDeLettres = std::distance (premiereLettre,premiereEspace);

    return nombreDeLettres;
}
//////////////////////////////////////////////////////////////////////////

// Question 2 ////////////////////////////////////////////////////////////
std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> vectorstring;
    std::string::const_iterator premièreLettreDunMot =  str.begin();
    std::string::const_iterator espaceEntreLesMots;
    while (premièreLettreDunMot != str.end() )
    {
        std::string stringDeTravail;
        premièreLettreDunMot = std::find_if_not (premièreLettreDunMot,str.end(), is_space);
        espaceEntreLesMots = std::find_if (premièreLettreDunMot,str.end(), is_space);
        
       
       for (premièreLettreDunMot; premièreLettreDunMot != espaceEntreLesMots; premièreLettreDunMot++)
       {
        stringDeTravail.push_back(*premièreLettreDunMot);
       }

       vectorstring.push_back(stringDeTravail);
        premièreLettreDunMot = espaceEntreLesMots;
        stringDeTravail.clear();
    }
   

    return vectorstring;
}
/////////////////////////////////////////////////////////////////////////

int main() {

std::string phrase {};
std::cout << " Donne moi une phrase, je vais te donner le nombre de lettre dans le premier mot... je sais que c'est une bien etrange requete : " << std::endl;
std::getline(std::cin, phrase);

int compteDeLettres = compteurDeLettre(phrase);

std::cout << "Le nombre de lettre dans le premier mot de ta phrase est " << compteDeLettres << std::endl;


std::vector<std::string> test = split_string("je ne sais pas si ca marche");
for (int i{}; i < test.size(); i++)
{std::cout << test[i] << " ";
}

}





