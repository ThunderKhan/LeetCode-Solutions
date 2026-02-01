from collections import defaultdict

def groupAnagrams(strs : list[str]) -> list[list[str]]:
    hashMap = defaultdict(list)

    for s in strs:
        frequencySignature = [0] * 26

        for char in s:
            frequencySignature[ord(char) - ord('a')] += 1
        
        key = tuple(frequencySignature)
        hashMap[key].append(s)

    return list(hashMap.values())

strs =  ['cat', 'tac', 'bat', 'tab']
print(groupAnagrams(strs))