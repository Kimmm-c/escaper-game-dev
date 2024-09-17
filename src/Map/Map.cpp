#include "Map.h"
#include "../Utils/Utils.h"
#include <iostream>

Map::Map(uint8_t w, uint8_t h)
        : width(w), height(h) {
    // Construct a graph with disconnected vertices
    for (uint8_t y = 0; y < height; y++) {
        for (uint8_t x = 0; x < width; x++) {
            // emplace allows constructing a pair and a vector directly inside the map
            // without creating temporary objects.
            graph.emplace(make_pair(x, y), set<pair<uint8_t, uint8_t>>{});
        }
    }

    // Construct the winning path
    vector<bool> visit = {true, false};
    pair<uint8_t, uint8_t> currentVertex = {0, 0};
    pair<uint8_t, uint8_t> dest = {width - 1, height - 1};

    winningPath.insert(currentVertex);

    while (currentVertex != dest) {
        vector<pair<uint8_t, uint8_t>> neighbors = getNeighbours(currentVertex);

        // Filter out invalid neighbors
        filterByCoordinate(neighbors);
        filterByDeadEnd(currentVertex, neighbors);
        filterByVisit(neighbors);

        uint8_t neighbourNumber = neighbors.size();
        for (uint8_t i = 0; i < neighbourNumber; i++) {
            // Randomly determine to visit the neighbor or not
            if (Utils::getRandomSelection<bool>(visit) || i == neighbourNumber - 1 || neighbors[i] == dest) {
                // Add neighbour to the path
                winningPath.insert(neighbors[i]);
                graph[currentVertex].insert(neighbors[i]);
                graph[neighbors[i]].insert(currentVertex);
                currentVertex = neighbors[i];
                break;
            }
        }
    }

//    cout << "{" << endl;
//    for (const pair<uint8_t, uint8_t> &vertex: winningPath) {
//        cout << "{" << static_cast<int>(vertex.first) << ", "
//             << static_cast<int>(vertex.second) << "}" << endl;
//    }
//    cout << "}" << endl;

    /*
     * Construct a graph by connecting the path to the remaining points
     */

    for (auto &graphIt: graph) {
        pair<uint8_t, uint8_t> currentVertex = graphIt.first;

        /*
         * If the current vertex is disconnected, visit the next valid neighbour until it hits a connected neighbour.
         */
        while (isDisconnected(currentVertex)) {
            vector<pair<uint8_t, uint8_t>> neighbours = getNeighbours(currentVertex);
            filterByCoordinate(neighbours);
            filterByDisconnection(neighbours);

            uint8_t neighbourSize = neighbours.size();

            for (uint8_t i = 0; i < neighbourSize; i++) {
                if (Utils::getRandomSelection<bool>(visit) || i == neighbourSize - 1) {
                    bool isDisconnectedNeighbour = isDisconnected(neighbours[i]);
                    graph[currentVertex].insert(neighbours[i]);
                    graph[neighbours[i]].insert(currentVertex);

                    if (isDisconnectedNeighbour) {
                        currentVertex = neighbours[i];
                    }

                    break;
                }
            }
        }
    }

//    cout << "{" << endl;
//    for (auto &graphIt: graph) {
//        const pair<uint8_t, uint8_t> &vertex = graphIt.first;
//        const set<pair<uint8_t, uint8_t>> &connectedNeighbors = graphIt.second;
//
//        cout << "(" << static_cast<int>(vertex.first) << ", " << static_cast<int>(vertex.second) << "): ";
//        cout << "[";
//        for (pair<uint8_t, uint8_t> neighbour: connectedNeighbors) {
//            cout << "(" << static_cast<int>(neighbour.first) << ", " << static_cast<int>(neighbour.second) << "), ";
//        }
//        cout << "]," << endl;
//    }
//    cout << "}" << endl;
}

void Map::draw() {
    // Draw 'walls' along the graph to create a map
    string map;

    for (uint8_t i = 0; i < width; i++) {
        map += " ___ ";
    }

    for (uint8_t y = 0; y < height; y++) {
        map += "\n";
        for (uint8_t x = 0; x < width; x++) {
            if (x == 0 || graph[make_pair(x - 1, y)].count(make_pair(x, y)) == 0) {
                map += "|";
            } else {
                map += " ";
            }

            if (y == height - 1 || graph[make_pair(x, y)].count(make_pair(x, y + 1)) == 0) {
                map += "___ ";
            } else {
                map += "    ";
            }

            if (x == width - 1) {
                map += "|";
            }
        }
    }

    cout << map << endl;
}

uint8_t Map::getWidth() const { return width; }

uint8_t Map::getHeight() const { return height; }

const map<pair<uint8_t, uint8_t>, set<pair<uint8_t, uint8_t>>> &Map::getGraph() const {
    return graph;
}

const set<pair<uint8_t, uint8_t>> &Map::getWinningPath() const {
    return winningPath;
}

vector<pair<uint8_t, uint8_t>> Map::getNeighbours(const pair<uint8_t, uint8_t> &vertex) const {
    vector<pair<uint8_t, uint8_t>> neighbours = {make_pair(vertex.first - 1, vertex.second),
                                                 make_pair(vertex.first + 1, vertex.second),
                                                 make_pair(vertex.first, vertex.second - 1),
                                                 make_pair(vertex.first, vertex.second + 1)};
    return neighbours;
}

void Map::filterByVisit(vector<pair<uint8_t, uint8_t>> &neighbors) {
    uint8_t i = 0;

    while (i < neighbors.size()) {
        if (isVisited(neighbors[i], winningPath)) {
            neighbors.erase(neighbors.begin() + i);
        } else {
            i++;
        }
    }
}

void Map::filterByCoordinate(vector<pair<uint8_t, uint8_t>> &neighbors) {
    uint8_t i = 0;

    while (i < neighbors.size()) {
        if (!isValidCoordinate(neighbors[i], width, height)) {
            neighbors.erase(neighbors.begin() + i);
        } else {
            i++;
        }
    }
}

void Map::filterByDeadEnd(pair<uint8_t, uint8_t> &currentVertex, vector<pair<uint8_t, uint8_t>> &neighbors) {
    uint8_t i = 0;

    while (i < neighbors.size()) {
        if (isDeadEnd(currentVertex, neighbors[i])) {
            neighbors.erase(neighbors.begin() + i);
        } else {
            i++;
        }
    }
}

void Map::filterByDisconnection(vector<pair<uint8_t, uint8_t>> &neighbors) {
    uint8_t i = 0;

    while (i < neighbors.size()) {
        if (isDisconnected(neighbors[i])) {
            neighbors.erase(neighbors.begin() + i);
        } else {
            i++;
        }
    }
}

bool Map::isValidCoordinate(pair<uint8_t, uint8_t> &vertex, uint8_t width, uint8_t height) const {
    return !(vertex.first < 0
             || vertex.first >= width
             || vertex.second < 0
             || vertex.second >= height);
}

bool Map::isVisited(pair<uint8_t, uint8_t> &vertex, set<pair<uint8_t, uint8_t>> &path) const {
    return path.count(vertex) > 0;
}

bool Map::isDeadEnd(pair<uint8_t, uint8_t> &currentVertex, pair<uint8_t, uint8_t> &neighbor) const {
    /*
     * Return true (dead end) if:
     * The current vertex is on the right end of the graph (x = width - 1) and the next visited vertex is above the current vertex.
     * OR The current vertex is at the top most of the graph (y = 0) and the next visited vertex is on the left of the current vertex.
     * OR The current vertex is on the left end of the graph (x = 0) and the next visited vertex is above the current vertex.
     * OR The current vertex is at the bottom most of the graph (y = height - 1) and the next visited vertex is on the left of the current vertex.
     */
    return (currentVertex.first == width - 1 && neighbor.second == currentVertex.second - 1)
           || (currentVertex.second == 0 && neighbor.first == currentVertex.first - 1)
           || (currentVertex.second == height - 1 && neighbor.first == currentVertex.first - 1)
           || (currentVertex.first == 0 && neighbor.second == currentVertex.second - 1);
}

bool Map::isDisconnected(const pair<uint8_t, uint8_t> &vertex) {
    return graph[vertex].empty();
}