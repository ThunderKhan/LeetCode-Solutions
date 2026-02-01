import re

def isPalindrome(s : str) -> bool:
    clean = re.sub(r"[^a-zA-Z0-9]+", "", s).lower()

    left = 0
    right = len(clean) - 1

    while left < right:
        if clean[left] != clean[right]:
            return False

        left += 1
        right -= 1
    
    return True

s = "A man, a plan, a canal: Panama"
print(isPalindrome(s))

s = "race a car"
print(isPalindrome(s))