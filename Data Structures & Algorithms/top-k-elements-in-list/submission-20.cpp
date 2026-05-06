class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;


        for(int x : nums){
            freq[x]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for(auto& s : freq){
            buckets[s.second].push_back(s.first);
        }

        vector<int> res;

        for(int i = buckets.size() - 1; i > 0; i--){
            for(int n : buckets[i]){
                res.push_back(n);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;


        
    }
};
