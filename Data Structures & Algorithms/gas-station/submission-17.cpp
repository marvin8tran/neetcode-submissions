class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gap = 0;
        int res = 0;
        int sum = 0;
        for(int i = 0; i < gas.size(); i++){
            gap += gas[i] - cost[i];
            if(gap < 0){
                res = i + 1;
                gap = 0;
            }
            sum += gas[i] - cost[i];
        }

        if(sum < 0){
            return -1;
        }

        return res;

    }
};
