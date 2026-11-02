"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        
        #heap of earliest possible fit time
        #shove as many into one (earliest end time)
        #since its smallest top, if it doesnt fit we MUST make a new room
        heap = []
        heapq.heapify(heap)

        intervals = sorted(intervals, key=lambda x: x.start)
        #1307
        #918

        #1,3  2, 6   7,8  4,5

        for val in intervals:
            if heap and heap[0] <= val.start:
                heapq.heappop(heap)
            heapq.heappush(heap, val.end)
        return len(heap)