class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int l = 0;
        int r = heights.size() - 1;

        int res = 0;
        while(l < r){
            int x = r - l;

            res = max(res, x * min(heights[l], heights[r]));
            
            
            if(heights[l] < heights[r]){
                l++;
            } else{
                r--;
            }
        }
        return res;


    }
};
