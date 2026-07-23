class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        freq = [0] * 26

        # Count characters in s
        for ch in s:
            freq[ord(ch) - ord('a')] += 1

        # Remove characters using t
        for ch in t:
            index = ord(ch) - ord('a')
            freq[index] -= 1

            if freq[index] < 0:
                return ch