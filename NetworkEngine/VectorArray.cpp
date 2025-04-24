#include "VectorArray.h"
#include "Netcode.h"

void VectorArray::add(const NetworkPacket& packet) {
    packets.push_back(packet); // Add the packet to the vector
}

NetworkPacket VectorArray::get(int index) const {
    if (index < 0 || index >= packets.size()) {
        throw std::out_of_range("Index out of range");
    }
    return packets[index]; // Return the packet at the specified index
}

int VectorArray::getSize() const {
    return packets.size(); // Return the size of the vector
}