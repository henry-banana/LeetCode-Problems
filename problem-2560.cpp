#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool canAssignNumber(const int& max_value, const vector<int>& nums, const int& k) {
        int count = 0;
        int size = nums.size();

        for (int i = 0; i < size; ++i) {
            if (nums[i] <= max_value) {
                count++;
                i++;
            }
        }

        return count >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while (low <= high) {
            int mid = low + ((high - low) / 2);

            if (canAssignNumber(mid, nums, k)) {
                ans = mid;
                mid = high - 1;
            } else {
                mid = low + 1;
            }
        }

        return ans;
    }
};

int main() {


    return 0;
}