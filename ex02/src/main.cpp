#include "Array.hpp"
#include <iostream>

int
main (void)
{
  // Test 1: Array vide
  Array<int> empty;
  std::cout << "Empty array size: " << empty.size () << std::endl;

  // Test 2: Array avec éléments
  Array<int> arr (5);
  for (unsigned int i = 0; i < arr.size (); i++)
    arr[i] = static_cast<int> (i) * 10;

  std::cout << "Original array: ";
  for (unsigned int i = 0; i < arr.size (); i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;

  // Test 3: Constructeur de copie (deep copy)
  Array<int> copy = arr;
  copy[0] = 999;
  std::cout << "After modifying copy[0]: original=" << arr[0]
            << " copy=" << copy[0] << std::endl;

  // Test 4: Exception
  try
    {
      std::cout << arr[10] << std::endl;
    }
  catch (const std::out_of_range &e)
    {
      std::cout << "Error: " << e.what () << std::endl;
    }
  const Array<int> constArr (5);
  int value = constArr[0];
  std::cout << "value at constArr index 0 = " << value << "\n";
  return (0);
}
