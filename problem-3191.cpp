#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void flipElement(vector<int>& nums, const int& index) {
        nums[index] ^= 1;
        nums[index + 1] ^= 1;
        nums[index + 2] ^= 1;
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operation = 0;

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] != 1) {
                flipElement(nums, i);
                operation++;
            }
        }

        if (nums[n - 2] == 0 || nums[n - 1] == 0) {
            operation = -1;
        } 

        return operation;
    }
};

int main() {


    return 0;
}