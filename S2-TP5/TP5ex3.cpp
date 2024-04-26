#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};


struct Card {
    CardKind kind;
    CardValue value;

// Question 2 et 3 //////////////////////////////////////
    int hash() const {   
        return static_cast<int>(kind) * 13 + static_cast<int>(value);
    }
};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}
////////////////////////////////////////////


// Question 1 //////////////////////////////////////
bool operator==(Card const& C1, Card const& C2){
   
    return (C1.kind == C2.kind && C1.value == C2.value );
}
///////////////////////////////////////////////////


// Question 4 //////////////////////////////////////
#include <vector>
std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::unordered_map<Card, int, std::hash<Card> > tableauAssociatif (std::vector<Card> cards)
{
    std::unordered_map<Card, int, std::hash<Card> > tableauAssociatifCartes;
    for (int i = 0; i < cards.size(); i++){
        
        if ( tableauAssociatifCartes.find(cards[i]) == tableauAssociatifCartes.end()) 
        {
        tableauAssociatifCartes[cards[i]] = 1;
        }
    
    else {
        tableauAssociatifCartes[cards[i]]++;
    }
    }
    return tableauAssociatifCartes;
};

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}
///////////////////////////////////////////////////


int main()
{   Card AsDePique { CardKind::Spade, CardValue::Ace};
    std::cout << "Essayons ma fonction de hachage parfaite, pour voir, ca ne va pas beaucoup nous avancer" << std::endl;
    std::cout<< "En choisissant comme carte l'As de Pique la fonction renvoie : " << AsDePique.hash() << std::endl;

    std::cout << "Nous allons maintenant tirer aléatoirement 100 cartes, par la suite je vais vous lister pour chaque carte combien de fois elle apparait (Z'est parti) :" << std::endl;
    std::vector<Card> cards = get_cards(100);
    std::unordered_map<Card, int, std::hash<Card> > tableauAssociatifDes100Cartes = tableauAssociatif (cards);
    std::unordered_map<Card, int, std::hash<Card>>::iterator begin_iterator {  tableauAssociatifDes100Cartes.begin() };
    std::unordered_map<Card, int, std::hash<Card>>::iterator end_iterator {  tableauAssociatifDes100Cartes.end() };
    
    for ( begin_iterator; begin_iterator != end_iterator;++ begin_iterator) 
    {
    
    std::string nom = card_name(begin_iterator->first);
   
    int compte = begin_iterator->second;
    
    std::cout << nom << ": " << compte << std::endl;
    }
}