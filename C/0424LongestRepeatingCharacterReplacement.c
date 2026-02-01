int characterReplacement(char* s, int k) {
    int n = strlen(s);
    int left = 0;
    int maxFreq = 0;
    int ans = 0;

    int freq[26] = {0};

    for (int right = 0; right < n; right++) {
        int idx = s[right] - 'A';
        freq[idx]++;

        if (freq[idx] > maxFreq) {
            maxFreq = freq[idx];
        }

        while (((right - left + 1) - maxFreq) > k) {
            int idxL = s[left] - 'A';
            freq[idxL]--;
            left++;
        }

        int windowLen = right - left + 1;
        if (windowLen > ans) {
            ans = windowLen;
        }
    }

    return ans;
}