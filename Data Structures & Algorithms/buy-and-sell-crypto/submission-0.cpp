class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int l = 0;
        int r = 1;
        int maxProf = 0;


        while(r < prices.size()){
            if(prices[r] < prices[l]){
                l = r;
            }
            maxProf = max(prices[r] - prices[l], maxProf);
            r++;
        }

        return maxProf;
    }
};
