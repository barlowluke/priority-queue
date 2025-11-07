#pragma once

#include <vector>
#include <queue>

int min_merge_cost(const std::vector<int>& fileSizes) {
    if (fileSizes.empty()) {
        return 0;
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int size : fileSizes) {
        pq.push(size);
    }

    // total I/O cost of merging files
    int total_cost = 0;
    
    while (pq.size() > 1) {
        int file1 = pq.top();
        pq.pop();

        int file2 = pq.top();
        pq.pop();

        int current_merge_cost = file1 + file2;
        total_cost += current_merge_cost;
        pq.push(current_merge_cost);
    }

    return total_cost;
}
