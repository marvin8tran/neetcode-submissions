"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:

        intervals = sorted(intervals, key=lambda x: x.start)
        prev_end = -float('inf')
        for val in intervals:
            if prev_end > val.start:
                return False
            prev_end = val.end
        return True

