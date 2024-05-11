#include "node.hpp"
#include <vector>
#include <iostream>


Node* create_node(int value)
{
    Node* newNode {new Node {value, nullptr, nullptr}};
    return newNode;
}

bool Node::is_leaf() const {
    if (this->left == nullptr && this->right == nullptr)
    {
        return true;
    }
    else 
    {
        return false;
    }

}

void Node::insert(int value) {

    if (value <= this->value)
    {
        if (this->left == nullptr)
        {
            this->left = create_node (value);
        }

        else if (this->left != nullptr)
        {
            this->left->insert(value);
        }
        
    }

    else if (value > this->value)
    {
        if (this->right == nullptr)
        {
            this->right = create_node (value);
        }

        else if (this->right != nullptr)
        {
            this->right->insert(value);
        }
    }

}

int Node::height() const {
    if (is_leaf() == true) 
    {
        return 1; 
    }
    else
    {
        int leftHauteur = 0;
        int rightHauteur = 0;

        if (this->left != nullptr) 
        {
            leftHauteur = this->left->height(); 
        }

        if (this->right != nullptr) 
        {
            rightHauteur= this->right->height(); 
        }

        return 1 + std::max(leftHauteur, rightHauteur); 
    }
}



void Node::delete_childs() {
    if (this->left != nullptr) 
    {
        this->left->delete_childs();
        delete this->left;
        this->left = nullptr;
    }

    if (this->right != nullptr) 
    {
        this->right->delete_childs();
        delete this->right;
        this->right = nullptr;
    }
}

    void Node::display_infixe() const {
    if (this->left != nullptr) // Si le sous-arbre gauche existe
    {
        this->left->display_infixe(); // On affiche le sous-arbre gauche
    }

    std::cout << this->value << " "; // On affiche la valeur du nœud courant

    if (this->right != nullptr) // Si le sous-arbre droit existe
    {
        this->right->display_infixe(); // On affiche le sous-arbre droit
    }
}



std::vector<Node const*> Node::prefixe() const 
{
    std::vector<Node const*> tableauParcoursPrefixe {};

    tableauParcoursPrefixe.push_back(this);

        if (this->left != nullptr) 
    {
        std::vector<Node const*> noeudsGauches = this->left->prefixe();
        tableauParcoursPrefixe.insert(tableauParcoursPrefixe.end(), noeudsGauches.begin(), noeudsGauches.end());
    }

     if (this->right != nullptr) 
    {
        auto noeudsDroits = this->right->prefixe();
        tableauParcoursPrefixe.insert(tableauParcoursPrefixe.end(), noeudsDroits.begin(), noeudsDroits.end());
    }

    return tableauParcoursPrefixe;
}

Node*& most_left(Node*& node){
    if ((*node).left == nullptr)
    {
        return node;
    }
    else if ((*node).left != nullptr)
    {
       return most_left((*node).left);
    }
}



bool remove(Node*& node, int value) 
{   
    if (node == nullptr) 
    {
        return false;
    }
    else if (value == node->value && node->is_leaf()) 
    {
        // On supprime le nœud courant
        delete node;
        // Comme on a une référence sur le pointeur du nœud courant, on le met à jour avec nullptr
        // Ainsi le parent du nœud courant aura un pointeur vers nullptr
        node = nullptr;
        // on retourne true car la suppression a été effectuée
        return true;
    }
    else if (value == node->value && node->left != nullptr && node->right == nullptr) 
    {
        Node* temporaire = node;
        node = node->left;
        delete temporaire;
        return true;
    }
    else if (value == node->value && node->left == nullptr && node->right != nullptr) 
    {
        Node* temporaire = node;
        node = node->right;
        delete temporaire;
        return true;
    }
      else if (value == node->value && node->left != nullptr && node->right != nullptr) 
    {
        
        Node*& mostLeftNode = most_left(node->right);
        node->value = mostLeftNode->value;
        delete mostLeftNode;
        mostLeftNode = nullptr;
        return true;
    }
}



void delete_tree(Node* node)
{
    if (node != nullptr)
    {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}



Node* create_Arbre(std::vector<int> TableauDesValeurs)
{
      if (TableauDesValeurs.empty())
    {
        return nullptr;
    }

    Node* Racine = create_node(TableauDesValeurs[0]);
    for (int i = 1; i < TableauDesValeurs.size(); i++)
    {
        (*Racine).insert(TableauDesValeurs[i]);
    }

    return Racine;
}




int SommeDesNoeuds (std::vector<Node const*> tableauCreeParPrefixe)
{
    int result {};
    for (int i {}; i < tableauCreeParPrefixe.size(); i++)
    {
        result += tableauCreeParPrefixe[i]->value;
    }

    return result;
}