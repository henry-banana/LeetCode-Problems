#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int missing = 0,
        repeated = 0,
        n = grid.size();
    vector<vector<int>> marked(n, vector(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int row = (grid[i][j] - 1) / n,
                col = (grid[i][j] - 1) % n;

            if (marked[row][col] != 0) {
                repeated = grid[i][j];
            }

            else {
                marked[row][col] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (marked[i][j] == 0) {
                missing = n * i + j + 1;
                break;
            }
        }
    }
    
    return {repeated, missing};
}

int main() {


    return 0;
}