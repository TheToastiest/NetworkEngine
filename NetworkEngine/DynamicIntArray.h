#pragma once
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>

class DynamicIntArray {
private:
    int* arr;       // Pointer to the dynamic array
    int size;       // Current number of elements
    int capacity;   // Maximum capacity of the array

public:
    DynamicIntArray();               // Constructor
    ~DynamicIntArray();              // Destructor
    void add(int value);             // Add an integer to the array
    int get(int index) const;        // Get an integer at a specific index
    int getSize() const;             // Get the current size of the array
    int getCapacity() const;         // Get the current capacity of the array
    void saveToFile(const std::string& filename) const; // Save the array to a file
    void loadFromFile(const std::string& filename);     // Load the array from a file
    void clearData();                // Clear the array
};