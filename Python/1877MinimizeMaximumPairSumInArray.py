def minPairSum(nums : list[int]) -> int:
    nums.sort()
    left = 0
    right = len(nums) - 1
    maxSum = float('-inf')

    while left < right:
        sum = nums[left] + nums[right]

        if sum > maxSum:
            maxSum = sum
        
        left += 1
        right -= 1
    
    return maxSum

tests = [
    ([3,5,2,3], 7, "Given example 1"),
    ([3,5,4,2,4,6], 8, "Given example 2"),
    ([1,1], 2, "Minimum size"),
    ([1,100000], 100001, "Extreme values"),
    ([5,5,5,5], 10, "All equal"),
    ([1,2,3,4], 5, "Perfect symmetry"),
    ([1,2,3,100], 101, "One dominant large"),
    ([10,1,9,2,8,3], 11, "Random order"),
    ([1,1,1,100,100,100], 101, "Many duplicates"),
    ([2,2,2,3], 5, "Unbalanced duplicates"),
    ([7,3,5,1], 8, "Reverse order"),
    ([1,50,50,50,50,1], 100, "Heavy middle"),
    ([4,4,4,4,4,4], 8, "All identical"),
    ([1,2,2,2,9,10], 11, "Clustered values"),
    ([100000,1,99999,2], 100001, "Large boundary sums"),
]

passed = 0

for i, (nums, expected, desc) in enumerate(tests, 1):
    actual = minPairSum(nums)
    if actual == expected:
        print(f"✅ PASS | Test {i}: {desc}")
        passed += 1
    else:
        print(f"❌ FAIL | Test {i}: {desc}")
        print(f"   Input: {nums}")
        print(f"   Expected: {expected}, Actual: {actual}")

total = len(tests)
if passed == total:
    print(f"\n🎉 All tests passed! ({passed}/{total})")
else:
    print(f"\n⚠️ {passed}/{total} tests passed")