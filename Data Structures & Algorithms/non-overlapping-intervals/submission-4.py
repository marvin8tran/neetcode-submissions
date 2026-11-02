class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        
        intervals = sorted(intervals, key=lambda x : x[1])
        res = 0
        prev_end = float('-inf')
        for i, (start, end) in enumerate(intervals):
            #if overlap, drop the longer end val
            #greedy shove as most classes in 1 day
            if prev_end <= start:
                prev_end = end
            else:
                res += 1
        return res
                
        