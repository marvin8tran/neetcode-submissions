class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        unordered_map<int, int> count;
        //num, count
        vector<vector<int>> buckets(nums.size() + 1);
        //freq, nums


        for(int n : nums){
            count[n]++;
        }


        for(auto& s : count){
            buckets[s.second].push_back(s.first);
        }

        vector<int> res;
        
        for (int i = buckets.size() - 1; i > 0; --i) {
            for (int n : buckets[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;



    }
};
