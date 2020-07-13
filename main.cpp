#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <array>

std::string GetUserInput() 
{
    std::cout << "Input calcuation: ";
    std::string in;
    std::getline(std::cin, in);
    return in;
}

bool ContainsSingleOperator(std::string input)
{
    int PlusCount = std::count(input.begin(), input.end(), '+');
    int AsterixCount = std::count(input.begin(), input.end(), '*');
    int MinusCount = std::count(input.begin(), input.end(), '-');
    int DivideCount = std::count(input.begin(), input.end(), '/');
    int TotalCount = PlusCount + AsterixCount + MinusCount + DivideCount;
    return TotalCount == 1;
}

char GetTheOperator(std::string input)
{
    if (std::count(input.begin(), input.end(), '+') == 1) { return '+'; }
    if (std::count(input.begin(), input.end(), '*') == 1) { return '*'; }
    if (std::count(input.begin(), input.end(), '-') == 1) { return '-'; }
    if (std::count(input.begin(), input.end(), '/') == 1) { return '/'; }
    return 'E';
}

std::array<float, 2> ParseInputToArray(std::string input, char Operator)
{
    std::array<float, 2> ParsedValues;
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    size_t Position = input.find(Operator, 0);
    input.insert(Position+1, " ");
    input.insert(Position, " ");
    std::stringstream StringStreamObj(input);    
    std::string voidme;
    StringStreamObj >> ParsedValues[0];
    StringStreamObj >> voidme;
    StringStreamObj >> ParsedValues[1];
    return ParsedValues;
}

float Add(float left, float right) 
{
    return left + right;
}
float Subtract(float left, float right) 
{
    return left - right;
}
float Multiply(float left, float right) 
{
    return left * right;
}
float Divide(float left, float right) 
{
    return left / right;
}

int main(int argc, char* argv[])
{
    while (1)
    {
        std::string UserInput = GetUserInput();
        bool ValidOperator = ContainsSingleOperator(UserInput);

        if (!ValidOperator) { std::cout << "Invalid Operator - please try again" << std::endl; continue; } 

        char Operator = GetTheOperator(UserInput);

        if (Operator == 'E') { std::cout << "Invalid Operator - I don't know how we got here" << std::endl; continue; }

        auto [left, right] = ParseInputToArray(UserInput, Operator);

        switch (Operator) 
        {
            case '+':
                std::cout << UserInput << "=" << Add(left, right) << std::endl;
                break;
            case '-':
                std::cout << UserInput << "=" << Subtract(left, right) << std::endl;
                break;
            case '*':
                std::cout << UserInput << "=" << Multiply(left, right) << std::endl;
                break;
            case '/':
                std::cout << UserInput << "=" << Divide(left, right) << std::endl;
                break;
        };


    }
}

