#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <iterator>

enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); 
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

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

// Question 1 /////////////////////////////////////////

Token make_token(float value)
{
    Token NewTokenValue {TokenType::OPERAND, value, {}};
    return NewTokenValue;
}

Token make_token(Operator op)
{
    Token NewTokenOperator {TokenType::OPERATOR, {}, op};
    return NewTokenOperator;
}
////////////////////////////////////////////////////////


// Question 2 /////////////////////////////////////////
std::vector<Token> tokenize(std::vector<std::string> const& words)
{
    std::vector<Token> tableauDeTokenises;
    int isItFloat {};
    Token tokenise {};
    float convertiEnFloat {};
    for (int i{}; i < words.size(); i++)
    {   
       
        isItFloat = is_operateur(words[i]);
        
        if (isItFloat == 0)
        {
            convertiEnFloat = std::stof(words[i]);
            tokenise = make_token(convertiEnFloat);
            tableauDeTokenises.push_back(tokenise);
        }

        else if (isItFloat == 1)
        {
            if (words[i] == "+")
            {
                Operator operateurChoisi {Operator::ADD};
                tokenise = make_token(operateurChoisi);
                tableauDeTokenises.push_back(tokenise);

            }

            else if (words[i] == "-")
            {
                Operator operateurChoisi {Operator::SUB};
                tokenise = make_token(operateurChoisi);
                tableauDeTokenises.push_back(tokenise);

            }

             else if (words[i] == "/")
            {
                Operator operateurChoisi {Operator::DIV};
                tokenise = make_token(operateurChoisi);
                tableauDeTokenises.push_back(tokenise);

            }

            else if (words[i] == "*")
            {
                Operator operateurChoisi {Operator::MUL};
                tokenise = make_token(operateurChoisi);
                tableauDeTokenises.push_back(tokenise);
            }
        }
        
    }

    return tableauDeTokenises;
}

////////////////////////////////////////////////////////////////////////////////

float npi_evaluate(std::vector<Token> const& tokens)
{
   
    std::stack<float> pileDeFloat;

    for (int i {}; i < tokens.size(); i++)
    {
       
        
        if (tokens[i].type == TokenType::OPERAND)
        {
            pileDeFloat.push(tokens[i].value);
        }

        else if (tokens[i].type == TokenType::OPERATOR)
        {
            float rightOperand { pileDeFloat.top() };
            pileDeFloat.pop();
            float leftOperand {pileDeFloat.top() };
            pileDeFloat.pop();

            if (tokens[i].op == Operator::ADD)
            {
                float result { leftOperand + rightOperand};
                pileDeFloat.push(result);
            }
                else if (tokens[i].op == Operator::SUB)
            {
                float result { leftOperand - rightOperand};
                pileDeFloat.push(result);
            }

                else if (tokens[i].op == Operator::DIV)
            {
                float result { leftOperand / rightOperand};
                pileDeFloat.push(result);
            }

                else if (tokens[i].op == Operator::MUL)
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

    std::vector<Token> vecteurDeToken = tokenize(tableauDeTokens);
    
    // Question 4 //////////////////////////////////////
    std::cout << npi_evaluate(vecteurDeToken) << std::endl;
    ////////////////////////////////////////////////////
}