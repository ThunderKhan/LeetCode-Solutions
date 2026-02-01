def sumFourDivisors(nums : list[int]) -> int:
    totalSum = 0

    for num in nums:

        divisorCount = 0
        divisorSum = 0

        i = 1
        while i * i <= num:
            if num % i == 0:
                j = num // i

                divisorCount += 1
                divisorSum += i

                if i != j:
                    divisorCount += 1
                    divisorSum += j

                if divisorCount > 4:
                    break

            i += 1
        
        if divisorCount == 4:
            totalSum += divisorSum
        
    return totalSum