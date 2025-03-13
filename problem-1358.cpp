#include <iostream>
#include <vector>
#include <string>

using std::cin, std::cout, std::vector, std::string;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(),
            count = 0,
            left = 0,
            right = 0;
        int freq[] = {0, 0, 0};
        
        while (right < n) {
            freq[s[right] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += n - right;
                freq[s[left] - 'a']--;
                left++;
            }
            right++;
        }

        return count;
    }
};

int main() {


    return 0;
}