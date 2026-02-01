def reverseWords(s : str) -> str:
    words = s.split()
    words = [word for word in words if word != '']
    words = reversed(words)
    result = " ".join(words)
    return result

s = 'One small step for a man, one giant leap for mankind.'
print(reverseWords(s))