#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> pos;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             if (nums[i] + nums[j] == target) {
    //                 pos.push_back(i);
    //                 pos.push_back(j);
    //             }
    //         }
    //     }
    //     return pos;
    // }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pos;
        map<int, int> pair;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (pair.find(complement) != pair.end()) {
                pos.push_back(pair[complement]);
                pos.push_back(i);
                break;
            }

            pair[nums[i]] = i;
        }
        
        return pos;
    }
};