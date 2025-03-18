#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> res;

        for (int x : nums) {
            if (res.count(x)) {
                res.erase(x);
            } else {
                res.insert(x);
            }
        }

        return (res.size() == 0);
    }
};

int main() {


    return 0;
}