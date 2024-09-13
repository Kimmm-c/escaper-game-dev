#ifndef MAP_H
#define MAP_H

#include<cstdint>
#include<utility>
#include<map>
#include<vector>
#include<set>


using namespace std;

class Map {
    uint8_t width;
    uint8_t height;
    map<pair<uint8_t, uint8_t>, vector<pair<uint8_t, uint8_t>>> graph;
    set<pair<uint8_t, uint8_t>> winningPath;

public:
    Map(uint8_t w, uint8_t h);

    void draw();

    const map<pair<uint8_t, uint8_t>, vector<pair<uint8_t, uint8_t>>> &getGraph() const;
    const set<pair<uint8_t, uint8_t>> &getWinningPath() const;
    vector<pair<uint8_t, uint8_t>> getNeighbours(pair<uint8_t, uint8_t>& vertex) const;

    bool isValidCoordinate(pair<uint8_t, uint8_t> &vertex, uint8_t width, uint8_t height) const;

    bool isVisited(pair<uint8_t, uint8_t>& vertex, set<pair<uint8_t, uint8_t>>& path) const;

private:
    uint8_t getWidth() const;

    uint8_t getHeight() const;

    void filterByCoordinate(vector<pair<uint8_t, uint8_t>>& neighbors);
    void filterByVisit(vector<pair<uint8_t, uint8_t>>& neighbors);
};

#endif