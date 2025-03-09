#include <iostream>
#include <vector>
#include <string>

#define faster std::ios::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

using std::cin, std::cout, std::vector, std::string;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(),
            black_block = 0,
            min_operation = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            if (blocks[i] == 'B') {
                black_block++;
            }

            if (i >= k - 1) {
                min_operation = std::min(k - black_block, min_operation);
                if (blocks[i - k + 1] == 'B') {
                    black_block--;
                }
            }
        }

        return min_operation;
    }
};

int main() {


    return 0;
}