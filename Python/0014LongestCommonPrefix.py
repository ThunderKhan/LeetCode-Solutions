def longestCommonPrefix(strs: list[str]) -> str:
    if not strs:
        return ''
    
    shortest = min(strs, key = len)

    for i in range(0, len(shortest)):
        char = strs[0][i]

        for s in strs:
            if s[i] != char:
                return shortest[:i]
        
    return shortest

strs = ['flower', 'flow', 'flight']
print(longestCommonPrefix(strs))