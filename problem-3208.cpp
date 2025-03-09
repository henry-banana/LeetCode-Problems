#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector;

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int results = 0,
                cur = 0,
                n = colors.size();
            
            for (int i = 1; i < n + k - 1; ++i) {
                if (colors[i % n] == colors[(i - 1) % n]) {
                    cur = i;
                }

                // 0 1 0 1 0 
                if (i - cur + 1 > k) {
                    cur += 1;
                }

                if (i - cur + 1 == k) {
                    results += 1;
                }
            }

            return results;
        }
    };

int main() {


    return 0;
}