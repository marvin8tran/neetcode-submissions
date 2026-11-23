class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        seen = defaultdict(list)

        for s in strs:
            key = [0] * 26
            for c in s:
                key[ord(c)-ord('a')] += 1
            key = ",".join(map(str,key))
            seen[key].append(s)
        return list(seen.values())
