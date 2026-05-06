class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxArea = 0;
        
        int leftMax = height[l];
        int rightMax = height[r];

       while(l < r){
            
            if(height[l] < height[r]){
                l++;
                leftMax = max(leftMax, height[l]);
                maxArea += leftMax - height[l];
                
            } else{
                r--;
                rightMax = max(rightMax, height[r]);
                maxArea += rightMax - height[r];
                
            }
       } 
       return maxArea;
    }
};
