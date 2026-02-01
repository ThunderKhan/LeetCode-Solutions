def checkIfPangram(sentence : str) -> bool:
    if len(sentence) < 26:
        return False
    
    lettersPresent = [False] * 26

    for char in sentence:
        lettersPresent[ord(char) - ord('a')] = True
    
    for present in lettersPresent:
        if not present:
            return False
    
    return True

sentence = "thequickbrownfoxjumpsoverthelazydog"
print(checkIfPangram(sentence))

sentence = 'leetcode'
print(checkIfPangram(sentence))