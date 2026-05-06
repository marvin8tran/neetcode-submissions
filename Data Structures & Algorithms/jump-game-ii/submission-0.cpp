class Solution {
public:
    int jump(vector<int>& nums) {
        
        int reach = 0;
        int jumps = 0;
        int end = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            reach = max(reach, nums[i] + i);
        
            if(i == end){
                end = reach;
                jumps++;
            }
            
        }
        return jumps;



    }
};
