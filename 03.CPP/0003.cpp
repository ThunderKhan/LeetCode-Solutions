#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();

        int left = 0;
        int maxLen = 0;
        std::unordered_set<char> seenChar;

        for (int right = 0; right < n; right++) {
            char current = s[right];

            while (seenChar.find(current) != seenChar.end()) {
                seenChar.erase(s[left]);
                left++;
            }

            seenChar.insert(current);
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    
    std::string s1 = "";
    std::string s2 = "aaaa";
    std::string s3 = "abcabcbb";
    std::string s4 = "pwwekew";

    std::cout << sol.lengthOfLongestSubstring(s1) << "\n";
    std::cout << sol.lengthOfLongestSubstring(s2) << "\n";
    std::cout << sol.lengthOfLongestSubstring(s3) << "\n";
    std::cout << sol.lengthOfLongestSubstring(s4) << "\n";
    
    return 0;
}