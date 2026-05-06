class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> m;
        //value, index


        for(int i = 0; i < temperatures.size(); i++){
            if (m.empty()){m.push({temperatures[i], i}); continue;};
        
            while(!m.empty() && temperatures[i] > m.top().first){
                res[m.top().second] = i - m.top().second;
                m.pop();
            }

            m.push({temperatures[i], i});
        }

        return res;
    }
};
