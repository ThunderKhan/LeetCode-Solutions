def strStr(haystack : str, needle : str) -> int:
    hIdx = 0
    nIdx = 0
    candidateStart = -1

    while hIdx < len(haystack):
        if haystack[hIdx] == needle[nIdx]:
            if nIdx == 0:
                candidateStart = nIdx

            nIdx += 1

            if nIdx == len(needle):
                return candidateStart

        else:
            nIdx = 0
            candidateStart = -1

        hIdx += 1
    
    return -1

haystack = "sadbutsad"
needle = "sad"
print(strStr(haystack, needle))