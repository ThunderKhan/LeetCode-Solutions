def minimumDifference(nums : list[int], k : int) -> int:
    if k <= 1:
        return 0

    nums.sort()
    n = len(nums)
    left = 0
    right = k - 1
    minDiff = float('inf')

    while right < n:
        currDiff = nums[right] - nums[left]

        if currDiff < minDiff:
            minDiff = currDiff
        
        left += 1
        right += 1

    if minDiff == float('inf'):
        return 0
    return minDiff

def run_tests():
    tests = [
        # (nums, k, expected, description)
        ([90], 1, 0, "Single element"),
        ([9,4,1,7], 2, 2, "Example case"),
        ([1,5,9], 3, 8, "k equals array length"),
        ([5,5,5,5], 3, 0, "All values equal"),
        ([1,2,3,4,5], 3, 2, "Already sorted increasing"),
        ([8,1,2,2,3], 3, 1, "Duplicates present"),
        ([0,0,10,10], 2, 0, "Zeros included"),
        ([5,100,3], 1, 0, "k = 1 always zero"),
        ([1,100000,50000,50001], 2, 1, "Large numeric gap"),
        ([1,2], 2, 1, "Minimum valid size"),
        ([1,3,6,10,15], 2, 2, "Increasing gaps"),
        ([4,7,9,1,2], 4, 6, "Window selection matters"),
        ([5,5,5,5,100], 4, 0, "Outlier should be ignored"),
        ([10,1,9,2,8,3], 3, 2, "Alternating values"),
    ]

    passed = 0

    for i, (nums, k, expected, desc) in enumerate(tests, 1):
        try:
            actual = minimumDifference(nums[:], k)
            if actual == expected:
                print(f"✅ PASS | Test {i}: {desc}")
                passed += 1
            else:
                print(f"❌ FAIL | Test {i}: {desc}")
                print(f"   Input: nums={nums}, k={k}")
                print(f"   Expected: {expected}, Actual: {actual}")
        except Exception as e:
            print(f"❌ ERROR | Test {i}: {desc}")
            print(f"   Exception: {e}")

    print("\nSummary:")
    if passed == len(tests):
        print(f"🎉 All tests passed! ({passed}/{len(tests)})")
    else:
        print(f"⚠️ {passed}/{len(tests)} tests passed")


if __name__ == "__main__":
    run_tests()