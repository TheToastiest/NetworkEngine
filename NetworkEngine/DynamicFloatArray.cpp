#include "DynamicFloatArray.h"
#include "Netcode.h"

// Constructor: Initializes the dynamic array
DynamicFloatArray::DynamicFloatArray() {
    size = 0;
    capacity = 6; // Initial capacity
    arr = new float[capacity];
}

// Destructor: Frees allocated memory
DynamicFloatArray::~DynamicFloatArray() {
    delete[] arr;
    arr = nullptr;
}

// Adds a float value to the array, resizing if necessary
void DynamicFloatArray::add(float value) {
    if (size >= capacity) {
        // Double the capacity
        capacity *= 2;
        float* newArr = new float[capacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    arr[size++] = value;
}

// Retrieves a float value from the array safely
float DynamicFloatArray::get(int index) const {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    throw std::out_of_range("Index out of range");
}

// Returns the current size of the array
int DynamicFloatArray::getSize() const {
    return size;
}

// Returns the current capacity of the array
int DynamicFloatArray::getCapacity() const {
    return capacity;
}

// Clears the array and resets its size
void DynamicFloatArray::clearData() {
    delete[] arr; // Free the old data
    arr = new float[capacity]; // Reallocate memory with the same capacity
    size = 0; // Reset size
}