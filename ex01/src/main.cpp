#include <iostream>
#include "iter.hpp"

// Fonction pour afficher un int
void printInt(int x)
{
    std::cout << x << " ";
}

// Fonction pour afficher un int const
void printIntConst(const int& x)
{
    std::cout << x << " ";
}

// Fonction pour incrémenter un int
void increment(int& x)
{
    x++;
}

// Fonction pour afficher une string
void printString(const std::string& s)
{
    std::cout << s << " ";
}

int main(void)
{
    // Test 1: Array d'int non-const avec fonction non-const
    std::cout << "Test 1 - Array int non-const, fonction non-const:" << std::endl;
    int arr1[5] = {1, 2, 3, 4, 5};
    iter(arr1, 5, printInt);
    std::cout << std::endl;

    // Test 2: Array d'int const avec fonction const
    std::cout << "Test 2 - Array int const, fonction const:" << std::endl;
    const int arr2[5] = {10, 20, 30, 40, 50};
    iter(arr2, 5, printIntConst);
    std::cout << std::endl;

    // Test 3: Modifier les éléments
    std::cout << "Test 3 - Avant increment: ";
    int arr3[4] = {1, 2, 3, 4};
    iter(arr3, 4, printInt);
    std::cout << std::endl << "Après increment: ";
    iter(arr3, 4, increment);
    iter(arr3, 4, printInt);
    std::cout << std::endl;

    // Test 4: Array de strings
    std::cout << "Test 4 - Array de strings:" << std::endl;
    std::string strs[3] = {"Hello", "World", "!"};
    iter(strs, 3, printString);
    std::cout << std::endl;

    return (0);
}
