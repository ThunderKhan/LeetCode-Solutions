def squareIsWhite(coordinates: str) -> bool:
    map = {
        'a' : 1,
        'b' : 2,
        'c' : 3,
        'd' : 4,
        'e' : 5,
        'f' : 6,
        'g' : 7,
        'h' : 8
    }

    squareSum = map[coordinates[0]] + int(coordinates[1])
    if(squareSum & 1 == 1):
        return True
    return False

# Test cases
test_cases = [
    ("a1", False),
    ("h1", True),
    ("a8", True),
    ("h8", False),
    ("b1", True),
    ("g6", True),
    ("d4", False),
    ("e5", False),
    ("c7", False),
    ("h3", True),
    ("b8", False),
    ("g1", False),
    ("f2", False),
    ("d7", True),
    ("c2", True),
    ("e8", True),
    ("h5", True),
    ("a4", True),
    ("b5", True),
    ("g7", False),
]

# Test runner
passed = 0
for i, (inp, expected) in enumerate(test_cases, 1):
    try:
        result = squareIsWhite(inp)
        if result == expected:
            print(f"Test {i} ✅ PASS: Input={inp}")
            passed += 1
        else:
            print(f"Test {i} ❌ FAIL: Input={inp}, Expected={expected}, Actual={result}")
    except Exception as e:
        print(f"Test {i} ❌ EXCEPTION: Input={inp}, Error={e}")

print(f"\nSummary: {passed}/{len(test_cases)} tests passed!")