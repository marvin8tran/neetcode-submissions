class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0;
        int maxL = 0;
        int maxR = 0;
        int r = height.size() - 1;
        

        while(l < r){
            maxL = max(height[l], maxL);
            maxR = max(height[r], maxR);

            if(maxL < maxR){
                res += maxL - height[l];
                l++;
            } else{
                res += maxR - height[r];
                r--;
            }
        }
        return res;
    }
};
