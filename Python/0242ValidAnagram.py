def isAnagram(s : str, t : str) -> bool:
    if len(s) != len(t):
        return False
    
    alphabet = {}

    for char in s:
        if char in alphabet:
            alphabet[char] += 1
        else: 
            alphabet[char] = 1
        
    for char in t:
        if char not in alphabet:
            return False
        elif alphabet[char] == 1:
            del alphabet[char]
        else:
            alphabet[char] -= 1
    
    return not alphabet

s = "anagram"
t = "naagram"
print(isAnagram(s, t))

s = "ab"
t = "ba"
print(isAnagram(s, t))