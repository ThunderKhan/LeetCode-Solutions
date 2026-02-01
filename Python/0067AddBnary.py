def addBinary(a : str, b : str) -> str:

    max_len = max(len(a), len(b))

    a = a.zfill(max_len)
    b = b.zfill(max_len)

    result = ""
    carry = 0

    for i in range(len(a) - 1, -1, -1):
        total = int(a[i]) + int(b[i]) + carry
        result_digit = total % 2
        carry = total // 2
        result = str(result_digit) + result
    
    if carry != 0:
        result = str(carry) + result
    
    return result

a = '1010'
b = '1011'
print(addBinary(a, b))