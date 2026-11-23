class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        tmp = strs[0]
        for s in strs:
            length = min(len(s), len(tmp))
            if s == "":
                return ""
            for i in range(length):
                if s[i] != tmp[i]:
                    if i == 0:
                        return ""
                    tmp = tmp[:i]
                    break
            tmp = tmp[:length]
        return tmp