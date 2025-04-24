#pragma once
#include <iostream>
#include <stdexcept>

class DynamicFloatArray {
private:
    float* arr;       // Pointer to the dynamic array
    int size;         // Current number of elements
    int capacity;     // Maximum capacity of the array

public:
    DynamicFloatArray();               // Constructor
    ~DynamicFloatArray();              // Destructor
    void add(float value);             // Add a float value to the array
    float get(int index) const;        // Get a float value at a specific index
    int getSize() const;               // Get the current size of the array
    int getCapacity() const;           // Get the current capacity of the array
    void clearData();                  // Clear the array
};