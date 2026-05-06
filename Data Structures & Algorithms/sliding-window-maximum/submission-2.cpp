class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        

        priority_queue<pair<int, int>> s; //val, index
        vector<int> res;


        for(int i = 0; i < k; i++){
            s.push({nums[i], i});
        }
        res.push_back(s.top().first);
       
       for(int i = k; i < nums.size(); i++){
            s.push({nums[i], i});
            while(s.top().second <= i - k){
                s.pop();
            }
            res.push_back(s.top().first);
       }

        return res;

    }
};
