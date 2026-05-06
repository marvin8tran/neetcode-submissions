class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxRes = 0;

        while(l < r){
            int curr = (r - l) * min(heights[l], heights[r]);
            maxRes = max(curr, maxRes);
            if(heights[l] > heights[r]){
                r--;
            }else{
                l++;
            }
        }

        return maxRes;



    }
};
