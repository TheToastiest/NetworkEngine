#include "Netcode.h"
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>



// ===== Implement ServerInstance Constructor ===== //
ServerInstance::ServerInstance(std::string reg, int shardSize)
    : region(reg), shardID(1), maxCapacity(shardSize), playerStates(shardSize) {
}

// ===== Multi-Threading Logic ===== //
std::mutex packetBufferMutex;

void handleConnections(ServerInstance &server) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Checking active players in " << server.region << " shard " << server.shardID << "...\n";
    }
}

void processPackets(VectorArray &packetBuffer) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::lock_guard<std::mutex> lock(packetBufferMutex);
        if (packetBuffer.getSize() > 0) {
            NetworkPacket packet = packetBuffer.get(0);
            std::cout << "Processing packet: " << packet.data << " from sender " << packet.senderID << "\n";
        }
    }
}

void updatePhysics(DynamicFloatArray& playerPositions) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // 60 FPS update cycle
        std::cout << "Updating player positions...\n";
    }
}

// ===== Server Handoff Logic ===== //
void transferPlayer(ServerInstance& currentServer, ServerInstance& destinationServer, const std::string& playerName) {
    if (destinationServer.connectedPlayers.getSize() < destinationServer.maxCapacity) {
        currentServer.connectedPlayers.add(playerName);
        destinationServer.connectedPlayers.add(playerName);
        std::cout << "Transferred " << playerName << " from " << currentServer.region << " to " << destinationServer.region << "\n";
    }
    else {
        std::cout << "Destination shard full. Auto-scaling triggered.\n";
    }
}

// ===== Auto-Scaling: Dynamic Shard Creation ===== //
void autoScale(ServerInstance& server, std::vector<ServerInstance>& shardList) {
    if (server.connectedPlayers.getSize() >= server.maxCapacity) {
        int newShardID = shardList.size() + 1;
        shardList.push_back(ServerInstance(server.region, server.maxCapacity));
        shardList.back().shardID = newShardID;

        std::cout << "New shard created: " << server.region << " Shard " << newShardID << " (Auto-Scaled)\n";
    }
}

// ===== ServerInstance: Add Player Function ===== //
void ServerInstance::addPlayer(const std::string& name) {
    if (connectedPlayers.getSize() < maxCapacity) {
        connectedPlayers.add(name);
        activeConnections.add(connectedPlayers.getSize());
        playerStates.set(connectedPlayers.getSize() - 1, true);
        std::cout << name << " added to " << region << " shard " << shardID << "\n";
    }
    else {
        std::cout << "Shard full. Auto-scaling triggered.\n";
    }
}

// ===== Main Execution: Testing the Netcode System ===== //
int main() {
    // Initialize a primary server shard
    ServerInstance NA_Shard1("NA", 100);
    std::vector<ServerInstance> shardList;
    shardList.push_back(NA_Shard1);

    // Simulate player connections
    std::cout << "Adding Players...\n";
    NA_Shard1.addPlayer("PlayerA");
    NA_Shard1.addPlayer("PlayerB");
    NA_Shard1.addPlayer("PlayerC");

    // Test shard auto-scaling (should create a new shard if needed)
    autoScale(NA_Shard1, shardList);
    
    // Simulate network packet transmission
    VectorArray packetBuffer;
    packetBuffer.add({ 101, "MoveForward", 1715600400.5f });
    packetBuffer.add({ 102, "Attack", 1715600415.2f });

    std::cout << "First Packet Sent: " << packetBuffer.get(0).data << "\n";

    // Test player movement syncing via physics updates
    DynamicFloatArray playerPositions;
    playerPositions.add(10.5f);
    playerPositions.add(20.3f);

    std::cout << "Player Position (X, Y): " << playerPositions.get(0) << ", " << playerPositions.get(1) << "\n";

    // Multi-threading execution
    std::cout << "Starting Multi-Threaded Systems...\n";
    std::thread connectionThread(handleConnections, std::ref(NA_Shard1));
    std::thread packetThread(processPackets, std::ref(packetBuffer));
    std::thread physicsThread(updatePhysics, std::ref(playerPositions));

    // Allow time for network simulation before termination
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Join threads before program exit
    connectionThread.join();
    packetThread.join();
    physicsThread.join();

    return 0;
}