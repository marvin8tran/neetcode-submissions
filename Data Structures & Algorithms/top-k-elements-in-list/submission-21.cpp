class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        //num, frequency
        for(int n : nums){
            freq[n]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        //idx is freq, vectoris values

        for(auto& x : freq){
            buckets[x.second].push_back(x.first);
        }

        vector<int> res;
        for(int i = buckets.size() - 1; i >= 0; i--){
            for(int b : buckets[i]){
                res.push_back(b);
                if(res.size() == k){
                    return res;
                }
            }
        }
        
        return res;
    }
};
