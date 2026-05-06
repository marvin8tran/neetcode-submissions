class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> cars;
        // position, speed

        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());

        stack<double> time;

        for(int j = position.size() - 1; j >= 0; j--){
            double curr = (double)(target - cars[j].first) / cars[j].second;

            if(j == position.size() - 1){
                time.push(curr);
                continue;
            }
            if(curr <= time.top()){
                continue;
            }
            time.push(curr);
        }
       
        return time.size();

    }
};
