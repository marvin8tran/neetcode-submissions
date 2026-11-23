class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        tmp = strs[0]
        for i in range(1, len(strs)):
            j = 0
            while j < min(len(strs[i]), len(tmp)):
                if strs[i][j] != tmp[j]:
                    break
                j += 1
            tmp = tmp[:j]
        return tmp