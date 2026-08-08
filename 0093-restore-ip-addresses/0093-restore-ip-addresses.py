class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []

        def backtrack(i, parts):
            if len(parts) == 4:
                if i == len(s):
                    ans.append(".".join(parts))
                return

            # Remaining characters must fit in remaining parts
            remaining_chars = len(s) - i
            remaining_parts = 4 - len(parts)

            if remaining_chars < remaining_parts or remaining_chars > 3 * remaining_parts:
                return

            for length in range(1, 4):
                if i + length > len(s):
                    break

                part = s[i:i + length]

                # Leading zero
                if length > 1 and part[0] == '0':
                    break

                # > 255
                if int(part) > 255:
                    break

                parts.append(part)
                backtrack(i + length, parts)
                parts.pop()

        backtrack(0, [])
        return ans