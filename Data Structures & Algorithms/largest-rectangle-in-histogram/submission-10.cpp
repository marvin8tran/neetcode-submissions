class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       
       stack<pair<int,int>> nums;
       //index, height
        int result = 0;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            //smallest bar in the group
            while(!nums.empty() && heights[i] < nums.top().second){
                int height = nums.top().second;
                int width = i - nums.top().first;
                result = max(result, height * width);
                start = nums.top().first;
                nums.pop(); 
            }
            nums.push({start, heights[i]});

        }

        while(!nums.empty()){
            int height = nums.top().second;
            int width = heights.size() - nums.top().first;
            result = max(result, height * width);
            nums.pop();
        }


        return result;

    }
};