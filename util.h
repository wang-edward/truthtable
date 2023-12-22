#pragma once
#include <vector>
#include <iostream>

inline int exp2(int x) {
    return 1 << x;
}

template <typename T>
std::string printVector(const std::vector<T>& vec) {
    std::string ans;
    ans += "[";
    for (const auto& element : vec) {
        ans += element + " ";
    }
    ans += "]";
    return ans;
}
