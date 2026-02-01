def isValid(s : str) -> bool:
    stack = []

    hashMap = {
        ')' : '(',
        ']' : '[',
        '}' : '{'
        }
    
    for char in s:
        if char in '({[':
            stack.append(char)
        else:
            if not stack or stack[-1] != hashMap[char]:
                return False
            stack.pop()
    
    return len(stack) == 0

s = '(){}[]'
print(isValid(s))