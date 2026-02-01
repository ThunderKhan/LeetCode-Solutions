def minNumber(nums1 : list[int], nums2 : list[int]) -> int:
    
    set2 = set(nums2)

    for digit in range(1, 10):
        if digit in nums1 and digit in set2:
            return digit
    
    small1 = float('inf')
    small2 = float('inf')

    for nums in nums1:
        if nums < small1:
            small1 = nums 
    
    for nums in nums2:
        if nums < small2:
            small2 = nums

    if small1 < small2:
        return (small1 * 10  + small2)
    else:
        return (small2 * 10  + small1)
    
nums1 = [3,5,2,6]
nums2 = [3,1,7]

print(minNumber(nums1, nums2))