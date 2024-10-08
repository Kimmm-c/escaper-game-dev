#ifndef UTILS_H
#define UTILS_H

#include<vector>
#include<random>
#include<cstdlib>

using namespace std;

class Utils {
public:
    template<typename T>
    static T getRandomSelection(vector<T>& list);
    static void setNonBlockingInput(bool enable);
    static void clearInputBuffer();
};

template<typename T>
T Utils::getRandomSelection(vector<T>& list) {
    // Seed with a real random value, if available
    random_device rd;
    // Initialize random engine with seed
    // Purpose: Construct a number generator to select a random index
    mt19937 gen(rd());
    // Define a distribution from 0 to the size of the vector - 1
    // Purpose: Ensure that the selected index is within range
    uniform_int_distribution<> dist(0, list.size() - 1);

    // Get a random index and return the corresponding element
    return list[dist(gen)];
}

#endif