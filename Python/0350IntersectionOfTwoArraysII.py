def intersection(nums1 : list[int], nums2 : list[int]) -> list[int]:
    if len(nums1) > len(nums2):
        large = nums1
        small = nums2
    else:
        large = nums2
        small = nums1
    
    frequencyMap = {}
    for num in small:
        if num in frequencyMap:
            frequencyMap[num] += 1
        else:
            frequencyMap[num] = 1
    
    result =[]
    for num in large:
        if (num in frequencyMap) and (frequencyMap[num] > 0):
            result.append(num)
            frequencyMap[num] -= 1
    
    return result

nums1 = [4, 9, 5, 4, 9]
nums2 = [9, 4, 9, 8, 4]

print(intersection(nums1, nums2))