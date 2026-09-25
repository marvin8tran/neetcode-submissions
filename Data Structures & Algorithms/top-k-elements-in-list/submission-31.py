class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        #num, freq

        buckets = [[] for _ in range(len(nums)+1)]
        #make a list of lists, freq index, nums
        for num, freq in count.items():
            buckets[freq].append(num)
        
        res = []
        for i in range(len(nums), 0, -1):
            for val in buckets[i]:
                res.append(val)
                if len(res) == k:
                    return res
        return res


        
        