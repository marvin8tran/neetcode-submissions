class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        //bucket sort
        // freq, num

        unordered_map<int, int> freq;

        for(int i : nums){
            freq[i]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
 
        for(const auto& p : freq){
            buckets[p.second].push_back(p.first);
        }

        vector<int> res;

        for(int i = buckets.size() - 1; i > 0; i--){
            for(int j : buckets[i]){
                res.push_back(j);
                if(res.size() == k){
                    return res;
                }
            }
            

        }
        return res;



    }
};
