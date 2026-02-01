def isSubsequence(s : str, t : str) -> bool:
    sIdx = 0
    tIdx = 0

    while (sIdx < len(s)) and (tIdx < len(t)):
        if(s[sIdx] == t[tIdx]):
            sIdx += 1
        tIdx += 1

    return sIdx == len(s)

s = "abc"
t = "ahbgdc"
print(isSubsequence(s, t))