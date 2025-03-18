#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int cur_count = 0,
            xor_count = 0;
        int max_window_size = 0;

        while (r < n) {
            cur_count += nums[r];
            xor_count ^= nums[r];
            
            while (cur_count != xor_count) {
                cur_count -= nums[l];
                xor_count ^= nums[l];
                l++;
            }

            max_window_size = max(max_window_size, r - l + 1);
            r++;
        }

        return max_window_size;
    }
};

int main() {


    return 0;
}