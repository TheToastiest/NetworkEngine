#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

class StringArray {
private:
    std::string* arr;  // Pointer to dynamically allocated string array
    int size;          // Number of elements in the array
    int capacity;      // Total allocated capacity

public:
    StringArray(int initialCapacity = 10);  // Constructor
    ~StringArray();                         // Destructor
    void add(const std::string& str);       // Add a string to the array
    std::string get(int index) const;       // Retrieve a string by index
    int getSize() const;                    // Get the current size
    void saveToFile(const std::string& filename) const; // Save the array to a file
    void loadFromFile(const std::string& filename);     // Load the array from a file
    void move(int index, int newIndex);     // Move a string to a new index
    void sort();                            // Sort strings alphabetically
    bool contains(const std::string& str) const; // Check if a string exists in the array
};