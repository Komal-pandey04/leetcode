class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()      # Remove leading and trailing spaces
        count = 0

        for i in range(len(s) - 1, -1, -1):
            if s[i] != ' ':
                count += 1
            else:
                break

        return count