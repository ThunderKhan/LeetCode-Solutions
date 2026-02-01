def characterReplacement(s : str, k : int) -> int:
    n = len(s)
    left = 0
    maxFreq = 0
    ans = 0
    freq = [0] * 26

    for right in range(n):
        idx = ord(s[right]) - ord('A')
        freq[idx] += 1
        maxFreq = max(maxFreq, freq[idx])

        while (right - left + 1 - maxFreq) > k:
            idxL = ord(s[left]) - ord('A')
            freq[idxL] -= 1
            left += 1
        
        ans = max(ans, (right - left + 1))
    
    return ans

s = "ABAB"
k = 2
print(characterReplacement(s, k))