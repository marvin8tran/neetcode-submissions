class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int,int>> nums;
        //value, index

        for(int i = 0; i < temperatures.size(); i++){
            while(!nums.empty() && temperatures[i] > nums.top().first){
                result[nums.top().second] = i - nums.top().second;
                nums.pop();
            }
            nums.push({temperatures[i], i});
        }
        return result;


    }
};
