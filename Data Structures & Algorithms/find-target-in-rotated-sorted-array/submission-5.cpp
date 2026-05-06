class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            

            //if mid < right num (normal order, else mid is chopped off end)
            if(nums[mid] < nums[r]) { // 4 5 1 2 3 4
                if(nums[mid] < target && target <= nums[r]){ //target within normal range 1-4
                    l = mid + 1;
                } else { //target is in chopped off area
                    r = mid - 1;
                }
            } else {
                if(nums[mid] > target && target >= nums[l]){
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
                
            }



        }

        return -1;

    }
};
