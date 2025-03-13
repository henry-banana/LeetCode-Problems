#include <iostream>
#include <vector>
#include <string>

using std::cin, std::cout, std::vector, std::string, std::max;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int size = rectangles.size();
        int max_indx = INT_MIN;
        int count = 0;
        vector<int> min_of_width_and_length(size, 0);
        
        // Choose min of width and length of a retangle to get a square
        for (int i = 0; i < size; ++i) {
            min_of_width_and_length[i] = (rectangles[i][0] < rectangles[i][1]) ? rectangles[i][0] : rectangles[i][1];
        }


        for (int i = 0; i < size; ++i) {
            max_indx = max(max_indx, min_of_width_and_length[i]);
        }
        
        for (int i = 0; i < size; ++i) {
            if (min_of_width_and_length[i] == max_indx) {
                count++;
            }
        }

        return count;
    }
};

int main() {


    return 0;
}