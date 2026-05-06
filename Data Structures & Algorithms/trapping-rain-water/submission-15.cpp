class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxL = height[left];
        int maxR = height[right];
        int vol = 0;

        while(left<right) {
            if (height[left]<=height[right]) {
                left++;
                if (height[left]>maxL) {
                maxL = height[left];
            }
                vol += maxL-height[left];
            } else {
                right--;
                if (height[right]>maxR) {
                maxR = height[right];
            }
                vol += maxR-height[right];
            }

            
            
        }
        return vol;
        
    }
};
