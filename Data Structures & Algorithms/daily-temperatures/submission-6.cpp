class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> s;
        //index, temp

        for(int i = 0; i < temperatures.size(); i++){
            while(!s.empty() && temperatures[i] > s.top().second){
                res[s.top().first] = i - s.top().first;
                s.pop();
            }
            s.push({i, temperatures[i]});
        }

        return res;
    }
};
