class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int,int>> s;
        vector<int> res(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++){
            while(!s.empty() && temperatures[i] > s.top().first){
                auto pair = s.top();
                s.pop();
                res[pair.second] = i - pair.second;
            }
            s.push({temperatures[i], i});
        }
        return res;
        
    }
};
