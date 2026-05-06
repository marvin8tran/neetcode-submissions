class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int l = 0;
        int r = nums.size() - 1;

        while(l < r){
            int mid = l + (r-l) / 2;
            if(nums[mid] > nums[r]){ // 6 7 1 2 3 4 5   |  2 3 1
                l = mid + 1;
            } else{ // 1 2 3, 3 1 2
                r = mid;
            }
        }

        return nums[l];


    }
};
