def defangIPaddr(address : str) -> str:
    
    returnAddress = ""
    for char in address:
        if char == ".":
            returnAddress += "[.]"
        else:
            returnAddress += char
        
    
    return returnAddress

address = "1.1.1.1"
print(defangIPaddr(address))