class Solution {
public:
    

    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        vector<int> temp(3, -1);

        for(int i = 0; i < triplets.size(); i++){
            bool swap = true;
            for(int j = 0; j < 3; j++){
                if(triplets[i][j] > target[j]){
                    swap = false;
                }
            }
            if(swap){
                for(int k = 0; k < 3; k++){
                    temp[k] = max(triplets[i][k], temp[k]);
                }
            }
        }

        for(int x = 0; x < 3; x++){
            if(target[x] != temp[x]){
                return false;
            }
        }

        return true;
    }
};
