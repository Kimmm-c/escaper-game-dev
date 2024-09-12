#ifndef UTILS_H
#define UTILS_H

#include<vector>
using namespace std;

class Utils {
public:
    template<typename T>
    static T getRandomSelection(vector<T>& list);
};

#endif