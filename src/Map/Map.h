#ifndef MAP_H
#define MAP_H

#include<cstdint>
#include<utility>
#include<map>
#include<vector>

using namespace std;

class Map {
    uint8_t width;
    uint8_t height;
    map<pair<uint8_t, uint8_t>, vector<pair<uint8_t, uint8_t>>> graph;
    vector<pair<uint8_t, uint8_t>> winningPath;

public:
    Map(uint8_t w, uint8_t h);

    void draw();

private:
    uint8_t getWidth() const;

    uint8_t getHeight() const;

    const map<pair<uint8_t, uint8_t>, vector<pair<uint8_t, uint8_t>>>& getGraph() const;
};

#endif