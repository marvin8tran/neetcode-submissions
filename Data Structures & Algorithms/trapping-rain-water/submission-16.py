class Solution:
    def trap(self, height: List[int]) -> int:

        l = 0
        r = len(height) - 1
        maxL = 0
        maxR = 0

        res = 0
        
        while l < r:
            maxL = max(height[l], maxL)
            maxR = max(height[r], maxR)
            if height[l] < height[r]:
                res += maxL - height[l]
                l += 1
            else:
                res += maxR - height[r]
                r -= 1

        return res

        
        