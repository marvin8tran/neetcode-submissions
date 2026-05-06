class Solution {
public:
    int trap(vector<int>& height) {
        
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        int maxL = 0;
        int maxR = 0;


        while(l < r){

            maxL = max(maxL, height[l]);
            maxR = max(maxR, height[r]);


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
