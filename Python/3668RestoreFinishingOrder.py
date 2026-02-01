def recoverOrder(order : list[int], friends : list[int]) -> list[int]:
    setFriends = set(friends)

    ans = []
    for participant in order:
        if participant in setFriends:
            ans.append(participant)
    
    return ans

order = [3, 1, 2, 5, 4]
friends = [1, 3, 4]

print(recoverOrder(order, friends))