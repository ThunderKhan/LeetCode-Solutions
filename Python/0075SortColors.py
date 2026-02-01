def sortColors(nums : list[int]) -> None:
    low = 0
    mid = 0
    high = len(nums) - 1

    while mid <= high:
        if nums[mid] == 0:

            temp = nums[mid]
            nums[mid] = nums[low]
            nums[low] = temp

            mid += 1
            low += 1
        
        elif nums[mid] == 1:
            mid += 1
        
        else:
            temp = nums[mid]
            nums[mid] = nums[high]
            nums[high] = temp

            high -= 1

nums = [2, 0, 2, 1, 1, 0]
sortColors(nums)
print(nums)