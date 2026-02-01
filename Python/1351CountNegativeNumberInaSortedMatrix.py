def countNegatives(grid : list[list[int]]) -> int:

    m = len(grid)
    n = len(grid[0])

    row = 0
    col = n - 1

    counter = 0

    while row < m and col >= 0:
        if grid[row][col] < 0:
            counter += (m - row)
            col -= 1
        else:
            row += 1

    return counter

grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
print(countNegatives(grid))

grid = [[3,2],[1,0]]
print(countNegatives(grid))