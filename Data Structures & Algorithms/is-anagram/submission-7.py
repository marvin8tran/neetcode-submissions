class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        tmp = [0] * 26
        if len(s) != len(t):
            return False
        for i in range(len(s)):
            tmp[ord(s[i])-ord('a')] += 1
            tmp[ord(t[i])-ord('a')] -= 1

        for j in range(26):
            if tmp[j] != 0:
                return False
        return True
        