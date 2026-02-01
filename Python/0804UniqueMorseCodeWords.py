def uniqueMorseRepresentation(words : list[str]) -> int:
    morse_list = [
        '.-','-...','-.-.','-..','.','..-.','--.','....','..','.---',
        '-.-','.-..','--','-.','---','.--.','--.-','.-.','...','-',
        '..-','...-','.--','-..-','-.--','--..'
    ]

    uniqueElements = set()

    for word in words:
        morse = ''

        for char in word:
            morse += morse_list[ord(char) - ord('a')]

        uniqueElements.add(morse)
    
    return len(uniqueElements)

words = ['gin', 'zen', 'gig', 'msg']
print(uniqueMorseRepresentation(words))