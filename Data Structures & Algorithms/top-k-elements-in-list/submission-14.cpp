class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //store how frequent each is
        //somehow sort it and return top frequent

        //bucket sort - 

        unordered_map<int, int> seen;
        //num, how many


        for(int i : nums){
            seen[i]++;
        }


        vector<vector<int>> buckets(nums.size() + 1);
        //freq, what nums

        for(auto p : seen){
            buckets[p.second].push_back(p.first);
        }

        vector<int> res;

        for(int i = buckets.size() - 1; i > 0; --i){
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
