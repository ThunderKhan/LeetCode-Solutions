def containsNearbyDuplicate(nums : list[int], k : int) -> bool:
    seenWindow = set()

    for i in range(len(nums)):
        if nums[i] in seenWindow:
            return True
        
        seenWindow.add(nums[i])

        if len(seenWindow) > k:
            seenWindow.discard(nums[i - k])
    
    return False

nums = [1,2,3,1]
k = 3

print(containsNearbyDuplicate(nums, k))