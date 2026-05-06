class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int fast = 0;
        int slow = 0;

        if(nums.size() == 2){
            return nums[0];
        }

        while(true){

            fast += 2;
            slow++;
            if(fast > nums.size()){
                fast -= nums.size();
            }
            if(slow > nums.size()){
                slow = 0;
            }

            if(nums[fast] == nums[slow] && fast != slow){
                return nums[fast];
            }
        }
        
        return 0;
        


    }
};
