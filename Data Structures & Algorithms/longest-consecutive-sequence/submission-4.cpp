class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        //rearrange to create a chain?
        //create a separate array, insert?

        unordered_map<int, int> m;
        //value, length
        //insert it
        //if it has a neighbor, left = length, right = length

        //iterate and just get max value
        int res = 0;

        for(int i : nums){
            if(!m[i]){ //new value
                m[i] = m[i-1] + m[i+1] + 1; //get new length, length left + right
                m[i - m[i-1]] = m[i];
                m[i + m[i+1]] = m[i];
            }
            res = max(res, m[i]);
        }
        return res;
    }
};
