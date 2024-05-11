#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <math.h>
#include <sstream>
#include <string>

#include "node.hpp"

// EXERCICE 2 //////////////////////////////////////////////////////////
int main() {
    std::vector<int> TableauDesValeurs {5, 3, 7, 2, 4, 6, 8, 1, 9, 0};
    Node* ArbreCree = create_Arbre(TableauDesValeurs);
    std::cout << "Regarde, je vais parcourir l'arbre que je viens de creer dans l'ordre infixe : ";
    ArbreCree->display_infixe();
    std::cout << std::endl;
    std::vector<Node const*> tableauCreeParPrefixe = ArbreCree->prefixe();
    int SommeDesNoeudsDeArbre = SommeDesNoeuds(tableauCreeParPrefixe);
    std::cout << "La somme des noeuds de l'arbe que l'on vient de creer est " << SommeDesNoeudsDeArbre << ". T'as vu mec, trop fort en calcul le boug'" << std::endl;
    int HauteurDeNotreBelArbre = (*ArbreCree).height();
    std::cout << "La hauteur de notre arbre est : " << HauteurDeNotreBelArbre << " ,il a bien grandit depuis le debut du TD, au debut il etait tout petit, et le voila deja grand, pret a parcourir le monde " << std::endl;
}
// ////////////////////////////////////////////////////////////////////
