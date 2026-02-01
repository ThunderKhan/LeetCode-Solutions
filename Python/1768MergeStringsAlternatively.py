def mergeAlternatively(word1 : str, word2 : str) -> str:
    len1 = len(word1)
    len2 = len(word2)

    i = 0
    j = 0

    temp = []

    while (i < len1) and (j < len2):
        temp.append(word1[i])
        i += 1

        temp.append(word2[j])
        j += 1
    
    while(i < len1):
        temp.append(word1[i])
        i += 1

    while(j < len2):
        temp.append(word2[j])
        j += 1
    
    result = "".join(temp)
    return result 

word1 = "abc"
word2 = "pqrstuvwxy"
print(mergeAlternatively(word1, word2))