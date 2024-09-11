#include "Map.h"

Map::Map(uint8_t w, uint8_t h)
        : width(w), height(h) {
    // Construct a graph with disconnected vertices
    for (uint8_t y; y < height; y++) {
        for (uint8_t x; x < width; x++ ) {
            // emplace allows constructing a pair and a vector directly inside the map
            // without creating temporary objects.
            graph.emplace(make_pair(x, y), vector<pair<uint8_t, uint8_t>>{});
        }
    }

    // Construct the winning path
    pair<uint8_t, uint8_t> currentVertex = {0, 0};

    winningPath.push_back(currentVertex);

    while (currentVertex.first != width - 1 && currentVertex.second != height - 1) {
        vector<pair<uint8_t, uint8_t>> neighbors = {{currentVertex.first - 1, currentVertex.second},
                                                    {currentVertex.first + 1, currentVertex.second},
                                                    {currentVertex.first, currentVertex.second - 1},
                                                    {currentVertex.first, currentVertex.second + 1}};

    }


    // Construct a graph by connecting the path to the remaining points

}

void Map::draw() {
    // Draw 'walls' along the graph to create a map

}

uint8_t Map::getWidth() const { return width; }

uint8_t Map::getHeight() const { return height; }

const map<pair<uint8_t, uint8_t>, vector<pair<uint8_t, uint8_t>>> &Map::getGraph() const {
    return graph;
}
