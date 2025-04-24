#include "DynamicIntArray.h"
#include "Netcode.h"

// Constructor: Initializes the dynamic array
DynamicIntArray::DynamicIntArray() {
    size = 0;
    capacity = 6; // Initial capacity
    arr = new int[capacity];
}

// Destructor: Frees allocated memory
DynamicIntArray::~DynamicIntArray() {
    delete[] arr;
    arr = nullptr;
}

// Adds an integer to the array, resizing if necessary
void DynamicIntArray::add(int value) {
    if (size >= capacity) {
        // Double the capacity
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    arr[size++] = value;
}

// Retrieves an integer from the array safely
int DynamicIntArray::get(int index) const {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    throw std::out_of_range("Index out of range");
}

// Returns the current size of the array
int DynamicIntArray::getSize() const {
    return size;
}

// Returns the current capacity of the array
int DynamicIntArray::getCapacity() const {
    return capacity;
}

// Saves the array to a file
void DynamicIntArray::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing");
    }
    for (int i = 0; i < size; ++i) {
        file << arr[i] << std::endl;
    }
    file.close();
}

// Loads integers from a file into the array
void DynamicIntArray::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for reading");
    }
    int value;
    while (file >> value) {
        add(value);
    }
    file.close();
}

// Clears the array and resets its size
void DynamicIntArray::clearData() {
    delete[] arr; // Free the old data
    arr = new int[capacity]; // Reallocate memory with the same capacity
    size = 0; // Reset size
}