#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>

class BoolArray {
private:
    bool* arr;  // Pointer to the boolean array
    int size;   // Size of the array

public:
    // Constructor
    BoolArray(int s);

    // Destructor
    ~BoolArray();

    // Function to set a value at a specific index
    void set(int index, bool value);

    // Function to get a value at a specific index
    bool get(int index) const;

    // Function to save the array to a file
    void saveToFile(const std::string& filename) const;

    // Function to load the array from a file
    void loadFromFile(const std::string& filename);

    // Function to get the size of the array
    int getSize() const;
};