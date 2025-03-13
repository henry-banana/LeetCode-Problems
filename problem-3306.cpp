#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::cin, std::cout, std::vector, std::string, std::unordered_map;

class Solution {
public:
    bool isVowel(const char& c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    vector<int> findNextConsonant(const string& word) {
        int n = word.size();
        int next = n;
        vector<int> next_consonant(n);

        for (int i = n; i >= 0; --i) {
            next_consonant[i] = next;
            if (!isVowel(word[i])) {
                next = i;
            }
        }

        return next_consonant;
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<int> next_consonant = findNextConsonant(word);
        long long count = 0;
        int consonants = 0;
        int left = 0,
            right = 0,
            prev = -1;
        unordered_map<char, int> vowel_freq;

        while (right < n) {
            if (prev != right) {
                if (isVowel(word[right])) {
                    vowel_freq[word[right]]++;
                }

                else {
                    consonants++;
                }

                prev = right;
            }


            if (right >= (5 + k - 1)) {
                if (vowel_freq.size() == 5 && consonants == k) {
                    count += next_consonant[right] - right;
                }

                // Move left pointer to right : Shrink window
                if ((vowel_freq.size() == 5 && consonants == k) || (consonants > k)) {
                    if (isVowel(word[left])) {
                        vowel_freq[word[left]]--;
                        if (vowel_freq[word[left]] == 0) {
                            vowel_freq.erase(word[left]);
                        }
                    }

                    else {
                        consonants--;
                    }

                    left++;
                }

                else {
                    right++;
                }
            }

            else {
                right++;
            }
        }

        return count;
    }
};

int main() {


    return 0;
}