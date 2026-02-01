def minimumAbsDifference(arr : list[int]) -> list[list[int]]:
    arr.sort()
    n = len(arr)
    result = []

    minDiff = float('inf')

    for i in range(n - 1):
        currDiff = arr[i + 1] - arr[i]

        if currDiff < minDiff:
            minDiff = currDiff
            result.clear()
            result.append([arr[i], arr[i + 1]])
        
        elif currDiff == minDiff:
            result.append([arr[i], arr[i + 1]])

    
    return result

arr = [4, 2, 1, 3]
print(minimumAbsDifference(arr))