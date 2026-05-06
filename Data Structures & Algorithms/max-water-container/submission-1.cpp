class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxArea = 0;

        while(l < r){
            
            int smallerHeight = min(heights[l], heights[r]);
            maxArea = max(maxArea, smallerHeight * (r - l));

            if(heights[l] > heights[r]){
                r--;
            }else{
                l++;
            }

        }
        return maxArea;

    }
};
