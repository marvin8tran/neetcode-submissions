class Solution {
public:
    int trap(vector<int>& height) {
        
        int l = 0;
        int r = height.size() - 1;
        int leftMax = height[l];
        int rightMax = height[r];
        int maxArea = 0;

        while(l < r){
            if(height[l] < height[r]){
                l++;
                leftMax = max(height[l], leftMax);
                maxArea += leftMax - height[l];
            }else{
                r--;
                rightMax = max(height[r], rightMax);
                maxArea += rightMax - height[r];
            }

        }


        return maxArea;



    }
};
