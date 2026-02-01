def romanToInt(s : str) -> int:
    romanNumeral = {
        'I' : 1, 'V' : 5, 'X' : 10,
        'L' : 50, 'C' : 100, 'D' : 500,
        'M' : 1000
        }
    
    total = 0
    prevValue = 0

    for char in reversed(s):
        currValue = romanNumeral[char]

        if currValue < prevValue:
            total -= currValue
        else:
            total += currValue
        
        prevValue = currValue
    
    return total

s = 'MCMXCIV'
print(romanToInt(s))