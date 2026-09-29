class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        m1, m2 = [0] * 26, [0] * 26

        for i in range(len(s1)):
            m1[ord(s1[i]) - ord('a')] += 1
            m2[ord(s2[i]) - ord('a')] += 1
        
        matches = 0
        for c in range(26):
            if m1[c] == m2[c]:
                matches += 1

        l = 0
        for r in range(len(s1), len(s2)):

            if matches == 26:
                return True
            
            idx = ord(s2[r]) - ord('a')
            m2[idx] += 1
            if m1[idx] == m2[idx]:
                matches += 1
            elif m1[idx] + 1 == m2[idx]:
                matches -= 1

            idx2 = ord(s2[l]) - ord('a')
            m2[idx2] -= 1
            if m1[idx2] == m2[idx2]:
                matches += 1
            elif m1[idx2] - 1 == m2[idx2]:
                matches -= 1
            l += 1
            
        return matches == 26
        