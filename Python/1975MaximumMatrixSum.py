def maxMatrixSum(self, matrix: List[List[int]]) -> int:
    total = 0
    count = 0
    min = float('inf')

    for row in matrix:
        for x in row:

            if x < 0:
                count += 1
                x = -x

            if x < min:
                min = x

            total += x
        
    if count % 2 == 0:
        return total
    else:
        return total - min * 2