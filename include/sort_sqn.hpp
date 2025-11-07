#pragma once

#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

std::vector<int> top_sqrtN_sorted(const std::vector<int>& A) {
    int N = A.size();
    if (N == 0) {
        return std::vector<int>();
    }

    int k = std::ceil(std::sqrt(N));

    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    for (int height : A) {
        if (min_heap.size() < k) {
            min_heap.push(height);
        } else if (height > min_heap.top()) {
            min_heap.pop();
            min_heap.push(height);
        }
    }

    std::vector<int> result;
    result.reserve(k);

    while (!min_heap.empty()) {
        result.push_back(min_heap.top());
        min_heap.pop();
    }

    std::reverse(result.begin(), result.end());
    return result;
   
}
