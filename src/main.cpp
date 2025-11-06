#include "sort_sqn.hpp"
#include "min_merge_cost.hpp"

int main() {
    // Problem 1
    std::vector<int> input_data = {1, 2, 3, 4, 8, 7, 6, 5, 9, 10};
    std::vector<int> topk = top_sqrtN_sorted(input_data);

    for (int i{0}; i < topk.size(); i++) {
        std::cout << topk[i] << " ";  //10 9 8 7
    }
    std::cout << "\n";

    // Problem 2
    std::vector<int> files = {10, 20, 30};
    std::cout << "Minimum total cost: " << min_merge_cost(files) << "\n"; // 90

    return 0;
}