def finalValueAfterOperations(operations : list[str]) -> int:
    finalValue = 0

    for operation in operations:
        if operation == "--X" or operation == "X--":
            finalValue -= 1
        else:
            finalValue += 1
    
    return finalValue

operations = ["--X","X++","X++"]
print(finalValueAfterOperations(operations))