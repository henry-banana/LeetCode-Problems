#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
private:
    int countRepairedCars(const int& time, const vector<int>& ranks) {
        int count = 0;

        for (int i = 0; i < ranks.size(); ++i) {
            count += sqrt(time / ranks[i]);
        }

        return count;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int low = 1,
            high = *max_element(ranks.begin(), ranks.end()) * cars * cars;

        int result = 0;

        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (countRepairedCars(mid, ranks) >= cars) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};

int main() {


    return 0;
}