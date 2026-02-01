def numSpecial(mat : list[list[int]]) -> int:
    rows = len(mat)
    cols = len(mat[0])

    rowCount = [0] * rows
    colCount = [0] * cols


    for i in range(rows):
        for j in range(cols):
            if mat[i][j] == 1:
                rowCount[i] += 1
                colCount[j] += 1
    
    special = 0
    for i in range(rows):
        for j in range(cols):
            if mat[i][j] == 1 and rowCount[i] == 1 and colCount[j] == 1:
                special += 1
    
    return special

mat = [[1,0,0], [0,0,1], [1,0,0]]
print(numSpecial(mat))