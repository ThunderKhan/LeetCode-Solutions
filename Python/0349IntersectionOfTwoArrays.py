def intersection(nums1 : list[int], nums2 : list[int]) -> list[int]:
    seen = set(nums1)
    result = []

    for num in nums2:
        if num in seen:
            result.append(num)
            seen.discard(num)
    
    return result

nums1 = [1, 2, 3, 4]
nums2 = [2, 2]

print(intersection(nums1, nums2))