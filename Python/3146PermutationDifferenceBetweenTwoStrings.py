def findPermuatationDifference(s : str, t : str) -> int:
    index_map = {}

    for i, char in enumerate(s):
        index_map[char] = i
    
    total = 0

    for j, char in enumerate(t):
        total += abs(j - index_map[char])
    
    return total

s = 'abc'
t = 'bac'

print(findPermuatationDifference(s, t))