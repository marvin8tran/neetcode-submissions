class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #bucketsort but trippy
        count = Counter(nums)

        #bucketsort is count frequency
        #make new with index = freq, list of #

        buckets = [[] for i in range(len(nums)+1)]
        for num, freq in count.items():
            buckets[freq].append(num)

        res = []
        for i in range(len(buckets)-1, 0, -1):
            for j in buckets[i]:
                res.append(j)
                if len(res) == k:
                    return res
        return res
        
