def findTheDifference(s : str, t : str) -> str:
    result = 0

    for char in s:
        result ^= ord(char)

    for char in t:
        result ^= ord(char)
    
    return chr(result)

s = ''
t = 'y'
print(findTheDifference(s, t))