class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        res = 0
        stack = []
        #indexes

        for i in range(len(heights) + 1):
            #pop until left height smaller
            while stack and (i == len(heights) or heights[i] < heights[stack[-1]]):
                height = heights[stack.pop()]
                # pop until left border reached
                width = i if not stack else i - stack[-1] - 1
                res = max(res, width * height)
            stack.append(i)
        return res