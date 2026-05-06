class Solution {
public:
    int trap(vector<int>& height) {
        
        int l = 0;
        int r = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int maxArea = 0;

        while(l < r){
            leftMax = max(height[l], leftMax);
            maxArea += leftMax - height[l];
            rightMax = max(height[r], rightMax);
            maxArea += rightMax - height[r];

            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }

        }


        return maxArea;



    }
};
