#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <iterator>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

// Question 3 /////////////////////////////////


// fonction qui détecte si le token est un flottant


// bool is_floating(std::string const& s)
// {
//     bool floating = false;
//     for (int a {}; a < s.size(); a++)
//     {
//         if (s[a] == '.' )
//         {
//             floating = true;
//             break;
//         }
//     }
//     return floating;
// }

// fonction qui détecte si le token est un opérateur 

bool is_operateur(std::string const& s)
{
    bool operateur = false;
    for (int a {}; a < s.size(); a++)
    {
        if (s[a] == '+' || s[a] == '-' || s[a] == '/' || s[a] == '*'  )
        {
            operateur = true;
            break;
        }
    }
    return operateur;
}

//////////////////////////////////////////////




float npi_evaluate(std::vector<std::string> const& tokens)
{
    int isItFloat {};
    std::stack<float> pileDeFloat;
    float convertiEnFloat {};

    for (int i {}; i < tokens.size(); i++)
    {
       
        isItFloat = is_operateur(tokens[i]);
        
        if (isItFloat == 0)
        {
            convertiEnFloat = std::stof(tokens[i]);
            pileDeFloat.push(convertiEnFloat);
        }

        else if (isItFloat == 1)
        {
            // Je récupère l'élément en haut de la pile
            float rightOperand { pileDeFloat.top() };
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            pileDeFloat.pop();
            float leftOperand {pileDeFloat.top() };
            pileDeFloat.pop();

            if (tokens[i] == "+")
            {
                float result { leftOperand + rightOperand};
                pileDeFloat.push(result);
            }

                else if (tokens[i] == "-")
            {
                float result { leftOperand - rightOperand};
                pileDeFloat.push(result);
            }

                else if (tokens[i] == "/")
            {
                float result { leftOperand / rightOperand};
                pileDeFloat.push(result);
            }

                else if (tokens[i] == "*")
            {
                float result { leftOperand * rightOperand};
                pileDeFloat.push(result);
            }
        }
    }

    return pileDeFloat.top();
}

int main() 
{
    // Question 1 //////////////////////////////////////
    std::string expressionNPI;
    std::cout << "Donne moi une expression mathematique en notation NPI (si tu en es capable) : ";
    std::getline(std::cin , expressionNPI);
    std::cout << std::endl;
    std::cout << expressionNPI << std::endl;
    // //////////////////////////////////////////////////


    // Question 2 //////////////////////////////////////
    std::vector<std::string> tableauDeTokens;
    tableauDeTokens = split_string(expressionNPI);
    // /////////////////////////////////////////////////
    

    // Question 4 //////////////////////////////////////
    std::cout << npi_evaluate(tableauDeTokens) << std::endl;
    ////////////////////////////////////////////////////

   

    // Question 5 /////////////////////////////////////
    std::vector<std::string> tableauDeTokensTest1;
    tableauDeTokensTest1 = split_string("3 4 +");

    std::vector<std::string> tableauDeTokensTest2;
    tableauDeTokensTest2 = split_string("2 12 + 5 +");

    std::vector<std::string> tableauDeTokensTest3;
    tableauDeTokensTest3 = split_string("3 4 11 5 + / +");

    std::vector<std::string> tableauDeTokensTest4;
    tableauDeTokensTest4 = split_string("4 5 2 * +");

    std::cout << "3 + 4 => 3 4 + = " <<npi_evaluate(tableauDeTokensTest1) << std::endl;
    std::cout << "2 + 12 + 5 => 2 12 + 5 + = " <<npi_evaluate(tableauDeTokensTest2) << std::endl;
    std::cout << "3 + 4 / ( 11 + 5 ) => 3 4 11 5 + / + = " <<npi_evaluate(tableauDeTokensTest3) << std::endl;
    std::cout << "4 + 5 * 2 => 4 5 2 * + = " <<npi_evaluate(tableauDeTokensTest4) << std::endl;
    //////////////////////////////////////////////////

}