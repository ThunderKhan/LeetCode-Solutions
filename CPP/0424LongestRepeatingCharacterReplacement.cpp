#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size();
    int left = 0;
    int maxFreq = 0;
    int ans = 0;
    vector<int> freq(26, 0);

    for (int right = 0; right < n; right++) {
        int idx = s[right] - 'A';
        freq[idx]++;
        maxFreq = max(maxFreq, freq[idx]);

        while (((right - left + 1) - maxFreq) > k) {
            int idxL = s[left] - 'A';
            freq[idxL]--;
            left++;
        }

        ans = max(ans, (right - left + 1));
    }

    return ans;
}

int main() {
    string s = "ABAB";
    int k = 2;
    int ans = characterReplacement(s, k);
    
    cout << ans << endl;

    return 0;
}