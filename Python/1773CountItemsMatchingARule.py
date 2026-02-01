def countMatches(items : list[list[str]], ruleKey : str, ruleValue : str) -> int:
    key_index = {
        "type" : 0,
        "color" : 1,
        "name" : 2
    }

    n = len(items)
    counter = 0

    for i in range(n):
        if items[i][key_index[ruleKey]] == ruleValue:
            counter += 1
    
    return counter

items = [
            ["phone","blue","pixel"],
            ["computer","silver","lenovo"],
            ["phone","gold","iphone"]
    ]
ruleKey = "color"
ruleValue = "silver"

print(countMatches(items, ruleKey, ruleValue))