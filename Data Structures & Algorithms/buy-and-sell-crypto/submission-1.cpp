class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int curr = prices[0];

        for(int n : prices){
            sum = max(n - curr, sum);
            curr = min(n, curr);
        }
        
        return sum;
    }
};
