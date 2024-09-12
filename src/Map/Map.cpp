#include "Map.h"

Map::Map(uint8_t w, uint8_t h)
        : width(w), height(h) {
    // Construct a graph with disconnected vertices
    for (uint8_t y; y < height; y++) {
        for (uint8_t x; x < width; x++) {
            // emplace allows constructing a pair and a vector directly inside the map
            // without creating temporary objects.
            graph.emplace(make_pair(x, y), vector<pair<uint8_t, uint8_t>>{});
        }
    }

    // Construct the winning path
    vector<bool> visit = {true, false};
    pair<uint8_t, uint8_t> currentVertex = {0, 0};

    winningPath.insert(currentVertex);

    while (currentVertex.first != width - 1 && currentVertex.second != height - 1) {
        vector<pair<uint8_t, uint8_t>> neighbors = getNeighbours(currentVertex);

        // Filter out invalid neighbors
        filterByCoordinate(neighbors);
        filterByVisit(neighbors);

        uint8_t neighbourNumber = neighbors.size();
        for (uint8_t i = 0; i < neighbourNumber; i++) {

        }
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

const set<pair<uint8_t, uint8_t>> &Map::getWinningPath() const {
    return winningPath;
}

vector<pair<uint8_t, uint8_t>> &Map::getNeighbours(pair<uint8_t, uint8_t> &vertex) const {
    vector<pair<uint8_t, uint8_t>> neighbours = {make_pair(vertex.first - 1, vertex.second),
                                                 make_pair(vertex.first + 1, vertex.second),
                                                 make_pair(vertex.first, vertex.second - 1),
                                                 make_pair(vertex.first, vertex.second + 1)};
    return neighbours;
}

bool Map::isValidCoordinate(pair<uint8_t, uint8_t> &vertex, uint8_t width, uint8_t height) const {
    return !(vertex.first < 0 || vertex.first >= width || vertex.second < 0 || vertex.second >= height);
}

bool Map::isVisited(pair<uint8_t, uint8_t> &vertex, set<pair<uint8_t, uint8_t>> &path) const {
    return path.count(vertex) > 0;
}