from typing import List


class Solution:
    def minimumGroups(self, words: List[str]) -> int:
        def smallest_rotation(s: str) -> str:
            n = len(s)

            if n <= 1:
                return s

            doubled = s + s

            i = 0
            j = 1
            k = 0

            while i < n and j < n and k < n:
                left = doubled[i + k]
                right = doubled[j + k]

                if left == right:
                    k += 1

                elif left > right:
                    i = i + k + 1

                    if i <= j:
                        i = j + 1

                    k = 0

                else:
                    j = j + k + 1

                    if j <= i:
                        j = i + 1

                    k = 0

            start = min(i, j)

            return doubled[start:start + n]

        brenolcavi = words

        groups = set()

        for word in brenolcavi:
            even_characters = word[::2]
            odd_characters = word[1::2]

            canonical_even = smallest_rotation(even_characters)
            canonical_odd = smallest_rotation(odd_characters)

            group_identifier = (canonical_even, canonical_odd)

            groups.add(group_identifier)

        return len(groups)