class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxL = height[0];
        int maxR = height[height.size() - 1];
        int maxArea = 0;

        while (l < r){
            
            if(height[l] > height[r]){
                maxR = max(height[r], maxR);
                maxArea += maxR - height[r];
                r--;

            } else{
                maxL = max(height[l], maxL);
                maxArea += maxL - height[l];
                l++;
            }
        }
        return maxArea;

        
    }
};
