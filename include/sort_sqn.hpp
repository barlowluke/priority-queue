#pragma once

#include <vector>
#include <math.h>
#include <queue>

std::vector<int> top_sqrtN_sorted(const std::vector<int>& A) {
   if (A.empty()) {
       return {};
   } 

    int N = A.size();
    int k = static_cast<int>(std::ceil(std::sqrt(N)));

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

    return result;
   
}
