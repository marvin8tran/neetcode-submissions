class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        vector<int> result(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++){
            int tmp = temperatures[i];
            while(!s.empty() && tmp > s.top().first){
                result[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({tmp, i});
        }
        return result;
    }
};
