#include "StringArray.h"
#include <algorithm> // For std::swap and std::sort
#include "Netcode.h"

// Constructor: Initializes array with specified capacity
StringArray::StringArray(int initialCapacity) : size(0), capacity(initialCapacity) {
    arr = new std::string[capacity]; // Allocate memory for the array
}

// Destructor: Frees allocated memory
StringArray::~StringArray() {
    delete[] arr; // Free the allocated memory
    arr = nullptr;
}

// Adds a string to the array, resizing if necessary
void StringArray::add(const std::string& str) {
    if (size >= capacity) {  // Ensure there is room to add the element
        capacity *= 2;  // Double the capacity
        std::string* newArr = new std::string[capacity];  // Allocate new memory
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];  // Copy existing elements
        }
        delete[] arr;  // Free old memory
        arr = newArr;  // Assign new memory
    }
    arr[size++] = str;  // Store the string and increment size
}

// Retrieves a string from the array safely
std::string StringArray::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range"); // Prevent invalid access
    }
    return arr[index];
}

// Returns the number of stored strings
int StringArray::getSize() const {
    return size;
}

// Saves the array to a file
void StringArray::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing");
    }
    for (int i = 0; i < size; ++i) {
        file << arr[i] << std::endl; // Write each string to the file
    }
    file.close();
}

// Loads strings from a file into the array
void StringArray::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for reading");
    }
    std::string line;
    while (std::getline(file, line)) {
        add(line); // Add each line to the dynamic array
    }
    file.close();
}

// Moves a string from one index to another
void StringArray::move(int index, int newIndex) {
    if (index < 0 || index >= size || newIndex < 0 || newIndex >= size) {
        throw std::out_of_range("Index out of range");
    }
    std::swap(arr[index], arr[newIndex]); // Swap elements
}

// Sorts the array alphabetically
void StringArray::sort() {
    std::sort(arr, arr + size); // Sort array in ascending order
}

// Checks if a string is already in the array
bool StringArray::contains(const std::string& str) const {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == str) {
            return true;
        }
    }
    return false;
}