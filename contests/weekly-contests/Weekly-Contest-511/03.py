from typing import List

class Solution:
    def transformStr(self, s: str, strs: List[str]) -> List[bool]:
        n = len(s)
        total_ones = s.count("1")

        prefix_ones= [0] * (n + 1)

        for i in range(n):
            prefix_ones[i + 1] = prefix_ones[i] + (s[i] == "1")

            answer = []

        for pattern in strs:
            fixed_ones = pattern.count("1")
            question_marks = pattern.count("?")

            ones_needed = total_ones - fixed_ones
            
            if ones_needed< 0 or ones_needed > question_marks:
                answer.append(False)
                continue
                    
            target = list(pattern)

            for i in range(n - 1, -1, -1):
                if target[i] == "?":
                    if ones_needed > 0:
                        target[i] = "1"
                        ones_needed -= 1
                    else:
                        target[i] = "0"
                
            target_prefix_ones = 0
            possible = True

            for i in range(n):
                if target[i] == "1":
                    target_prefix_ones += 1

                if target_prefix_ones > prefix_ones[i + 1]:
                    possible = False 
                    break
                
            answer.append(possible)
        
        return answer