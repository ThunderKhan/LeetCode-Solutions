def convertToTitle(columnNumber: int) -> str:
    temp = ''

    while columnNumber > 0:
        columnNumber -= 1
        temp += chr(65 + (columnNumber % 26))
        columnNumber //= 26

    return temp[::-1]


columnNumber = 701
print(convertToTitle(columnNumber))