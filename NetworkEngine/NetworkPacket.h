#pragma once
#include <string>

struct NetworkPacket {
    int senderID;
    std::string data;
    float timestamp;
};