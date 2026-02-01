def flipAndInvertImage(image : list[list[int]]) -> list[list[int]]:
    n = len(image)

    for row in image:
        left, right = 0, n - 1

        while left <= right:
            temp = row[left]
            row[left] = 1 - row[right]
            row[right] = 1 - temp

            left += 1
            right -= 1
    
    return image

image = [[1,1,0],[1,0,1],[0,0,0]]
print(flipAndInvertImage(image))