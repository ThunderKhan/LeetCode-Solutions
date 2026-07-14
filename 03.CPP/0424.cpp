#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int n = s.size();

        int left = 0;
        int ans = 0;
        int maxFreq = 0;

        std::vector<int> freq(26, 0);

        for (int right = 0; right < n; right++) {
            int idx = s[right] - 'A';
            freq[idx]++;
            maxFreq = std::max(maxFreq, freq[idx]);

            while (((right - left + 1) - maxFreq) > k) {
                int idxL = s[left] - 'A';
                freq[idxL]--;
                left++;
            }

            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    std::string s = "ABAB";
    int k = 2;

    int result = sol.characterReplacement(s, k);
    std::cout << result << "\n";

    return 0;
}