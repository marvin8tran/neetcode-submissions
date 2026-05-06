class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[nums[0]];
        int slow = nums[0];


        while(fast != slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        //reaches the beginning of the cycle?
        int slow2 = 0;
        while(true){
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow == slow2){
                return slow;
            }

        }
    }
};
