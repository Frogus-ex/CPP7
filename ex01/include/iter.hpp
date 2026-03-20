#pragma once

#include <iostream>
#include <string>

template <typename T, typename F>
void
iter (T *array, const int size, F function)
{
  for (int i = 0; i < size; i++)
    function (array[i]);
}

template <typename T, typename F>
void
iter (const T *array, const int size, const F function)
{
  for (int i = 0; i < size; i++)
    function (array[i]);
}
