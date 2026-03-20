#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

template <typename T> class Array
{
private:
  T *data;
  int aSize;

public:
  Array ();
  Array (int n);
  ~Array ();
  Array (const Array &copy);
  Array &operator= (const Array &other);
  T &operator[] (int index);
  const T &operator[] (int n) const;
  int size () const;
};

template <typename T> Array<T>::Array () : data (NULL), aSize (0)
{
  std::cout << "Empty array created" << std::endl;
}

template <typename T> Array<T>::Array (int n) : data (NULL), aSize (n)
{
  data = new T[n]();
  std::cout << "Array of aSize " << n << " created" << std::endl;
}

template <typename T> Array<T>::~Array () { delete[] data; }

template <typename T>
Array<T>::Array (const Array &copy) : data (NULL), aSize (0)
{
  *this = copy;
}

template <typename T>
Array<T> &
Array<T>::operator= (const Array &other)
{
  if (this != &other)
    {
      if (data != NULL)
        delete[] data;
      aSize = other.aSize;
      if (aSize == 0)
        data = NULL;
      else
        {
          data = new T[aSize]();
          for (int i = 0; i < aSize; i++)
            data[i] = other.data[i];
        }
    }
  return (*this);
}

template <typename T>
T &
Array<T>::operator[] (int index)
{
  if (index >= aSize || index < 0)
    throw std::out_of_range ("index out of range\n");
  return (data[index]);
}

template <typename T>
const T &
Array<T>::operator[] (int index) const
{
  if (index >= aSize || index < 0)
    throw std::out_of_range ("index out of range\n");
  return (data[index]);
}

template <typename T>
int
Array<T>::size () const
{
  return (aSize);
}
