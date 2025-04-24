#pragma once
#include <vector>
#include "NetworkPacket.h" // Include the new header for NetworkPacket

class VectorArray {
private:
    std::vector<NetworkPacket> packets; // Store NetworkPacket objects

public:
    void add(const NetworkPacket& packet); // Add a NetworkPacket
    NetworkPacket get(int index) const;   // Get a NetworkPacket by index
    int getSize() const;                  // Get the current size of the array
};