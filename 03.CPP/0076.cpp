#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::unordered_map<char, int> need;

        for (char c : t) {
            need[c]++;
        }

        int required = t.length();
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {

            if (need[s[right]] > 0) {
                required--;
            }

            need[s[right]]--;

            while (required == 0) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                need[s[left]]++;

                if (need[s[left]] > 0) {
                    required++;
                }

                left++;
            }

        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};

int main() {
    Solution sol;

    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";

    std::string result = sol.minWindow(s, t);
    std::cout << "\nThe correct substring is: " << result << "\n";

    return 0;
}