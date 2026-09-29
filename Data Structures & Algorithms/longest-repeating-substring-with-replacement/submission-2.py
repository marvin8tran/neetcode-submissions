class Solution:
    def characterReplacement(self, s: str, k: int) -> int:

        maxf = 0
        d = defaultdict(int)
        l = 0
        res = 0

        for r in range(len(s)):
            d[s[r]] += 1
            maxf = max(d[s[r]], maxf)

            while r - l + 1 - maxf > k:
                d[s[l]] -= 1
                l += 1
            res = max(res, r - l + 1)
        return res



        
        