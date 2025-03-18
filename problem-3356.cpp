#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int pos = 0,
            sum = 0;
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            while (sum + diff[i] < nums[i]) {
                if (pos == queries.size()) {
                    return -1;
                }

                int start = queries[pos][0];
                int end = queries[pos][1];
                int value = queries[pos][2];

                if (end < i) {
                    continue;
                }

                diff[max(start, i)] += value;
                diff[end + 1] -= value;
            }
            sum += diff[i];
        }

        return pos;
    }
};

int main() {


    return 0;
}