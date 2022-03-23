// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function

using namespace std;

template<class T>
class SimpleVector
{
private:
    T* aptr;          // To point to the allocated array
        // Number of elements in the array
    void memError();  // Handles memory allocation errors
    void subError();  // Handles subscripts out of range

public:
    // Default constructor
    SimpleVector()
    {
        aptr = 0;
        arraySize = 0;
    }
     int arraySize;
    // Constructor declaration
    SimpleVector(int);

    // Copy constructor declaration
    SimpleVector(const SimpleVector&);

    // Destructor declaration
    ~SimpleVector();

    // Accessor to return the array size
    int size() const
    {
        return arraySize;
    }

    // Accessor to return a specific element
    T getElementAt(int position);

    // Overloaded [] operator declaration
    T& operator[](const int&);

    void push_back(int);

    void pop_back(int);
};



template<class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    // Allocate memory for the array.
    try
    {
        aptr = new T[s];
    }
    catch (bad_alloc)
    {
        memError();
    }

    // Initialize the array.
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}


template<class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj)
{
    // Copy the array size.
    arraySize = obj.arraySize;

    // Allocate memory for the array.
    aptr = new T[arraySize];
    if (aptr == 0)
        memError();

    // Copy the elements of obj's array.
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}




template<class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete[] aptr;
}



template<class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR:Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}




template<class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}


template<class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}



template<class T>
T& SimpleVector<T>::operator[](const int& sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}
#endif

template <class T>
void SimpleVector<T>::push_back(int newval) {
    // Allocate memory for the array in the temporary array.
    T* tmpArray = new T[arraySize + 1];

    // Copy the elements of old array.
    for (int count = 0; count < arraySize; count++)
        *(tmpArray + count) = *(aptr + count);

    // Push new value
    *(tmpArray + arraySize) = newval;

    // Delete old array
    delete[] aptr;

    // Copy array
    aptr = tmpArray;

    // Increase size
    arraySize++;
}
template <class T>
void SimpleVector<T>::pop_back(int newval) {
    // Allocate memory for the array in the temporary array.
    T* tmpArray = new T[arraySize + 1];

    // Copy the elements of old array.
    for (int count = 0; count < arraySize; count++)
        *(tmpArray + count) = *(aptr + count);

    // Push new value
    *(tmpArray - arraySize) = newval;

    // Delete old array
    delete[] aptr;

    // Copy array
    aptr = tmpArray;

    // Increase size
    arraySize--;
}