def titleToNumber(columnTitle : str) -> int:
    columnNumber = 0

    for char in columnTitle:
        columnNumber = columnNumber * 26 + (ord(char) - 64)
    
    return columnNumber

columnTitle = 'ZY'
print(titleToNumber(columnTitle))