def maxArea(height : list[int]) -> int:
    n = len(height)
    max_Area = float('-inf')

    left = 0
    right = n - 1

    while left < right:
        width = abs(left - right)
        length = 0
        if height[left] <= height[right]:
            length = height[left]
        else:
            length = height[right]

        currArea = length * width
        if currArea > max_Area:
            max_Area = currArea
        
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    
    return max_Area

height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
print(f"The maximum water that can be held is {maxArea(height)}")