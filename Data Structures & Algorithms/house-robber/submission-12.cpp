class Solution {
public:
    int rob(vector<int>& nums) {

        int a = 0;
        int b = 0;

        for(int n : nums){
            int tmp = max(a + n, b);
            a = b;
            b = tmp;
        }

        return b;
        
    }
};
