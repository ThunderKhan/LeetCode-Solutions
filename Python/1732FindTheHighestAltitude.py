def largestAltitude(gain : list[int]) -> int:
    maxAltitude = 0
    currAltitude = 0

    for i in range(len(gain)):
        currAltitude += gain[i]

        if currAltitude > maxAltitude:
            maxAltitude = currAltitude
    
    return maxAltitude

gain = [-4,-3,-2,-1,4,3,2]
print(largestAltitude(gain))