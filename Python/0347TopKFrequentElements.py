def topKFrequent(nums : list[int], k : int) -> list[int]:
    n = len(nums)
    buckets = [0] * (n + 1)
    hashMap = {}

    for num in nums:
        if num in hashMap:
            hashMap[num] += 1
        else:
            hashMap[num] = 1

    for num, freq in hashMap.items():
        if buckets[freq] == 0:
            buckets[freq] = [num]
        else:
            buckets[freq].append(num)

    result = []
    for i in range(n, -1, -1):
        if buckets[i] != 0:
            result.extend(buckets[i])
        if len(result) == k:
            break
    
    return result


nums = [1,1,1,2,2,3]
k = 2

print(topKFrequent(nums, k))