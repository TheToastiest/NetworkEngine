#pragma once

#include "NetworkPacket.h"
#include "BoolArray.h"
#include "DynamicIntArray.h"
#include "DynamicFloatArray.h"
#include "VectorArray.h"
#include "StringArray.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>

// ===== Server Instance Management ===== //
struct ServerInstance {
    std::string region;
    int shardID;
    StringArray connectedPlayers;
    DynamicIntArray activeConnections;
    BoolArray playerStates;
    int maxCapacity;

    ServerInstance(std::string reg, int shardSize);
    void addPlayer(const std::string& name);
};

// ===== Multi-Threading Functions ===== //
void handleConnections(ServerInstance& server);
void processPackets(VectorArray& packetBuffer);
void updatePhysics(DynamicFloatArray& playerPositions);

// ===== Server Handoff & Auto-Scaling ===== //
void transferPlayer(ServerInstance& currentServer, ServerInstance& destinationServer, const std::string& playerName);
void autoScale(ServerInstance& server, std::vector<ServerInstance>& shardList);
