#include "BoolArray.h"
#include "Netcode.h"

// Constructor
BoolArray::BoolArray(int s) : size(s) {
    arr = new bool[size]; // Allocate memory for the array
    for (int i = 0; i < size; i++) {
        arr[i] = false; // Initialize all elements to false
    }
}

// Destructor with safety check
BoolArray::~BoolArray() {
    if (arr) { // Ensure arr is not null before deleting
        delete[] arr;
        arr = nullptr;
    }
}

// Function to set a value at a specific index
void BoolArray::set(int index, bool value) {
    if (index >= 0 && index < size) {
        arr[index] = value;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

// Function to get a value at a specific index
bool BoolArray::get(int index) const {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    throw std::out_of_range("Index out of range");
}

// Function to save the array to a file
void BoolArray::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing");
    }
    for (int i = 0; i < size; i++) {
        file << arr[i] << " "; // Write each element to the file
    }
    file.close();
}

// Function to load the array from a file
void BoolArray::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for reading");
    }
    for (int i = 0; i < size; i++) {
        file >> arr[i]; // Read each element from the file
    }
    file.close();
}

// Function to get the size of the array
int BoolArray::getSize() const {
    return size;
}

// Function to test BoolArray implementation
/*int main() {
    try {
        BoolArray arr(10); // Create a BoolArray of size 10
        arr.set(0, true); // Set the first element to true
        arr.set(1, false); // Set the second element to false
        arr.saveToFile("bool_data.txt"); // Save the array to a file
        arr.loadFromFile("bool_data.txt"); // Load the array from a file

        std::cout << "Value at index 0: " << arr.get(0) << std::endl;
        std::cout << "Value at index 1: " << arr.get(1) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}*/