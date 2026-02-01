def findNumber(nums : list[int]) -> int:
    counter = 0

    for num in nums:
        if (10 <= num <= 99) or (1000 <= num <= 9999) or (num == 100000){
            counter += 1
        }

    return counter