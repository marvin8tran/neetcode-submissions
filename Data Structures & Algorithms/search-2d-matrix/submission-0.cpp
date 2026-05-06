class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // <= <= <=
        //half the row half the col, smaller + smaller
        int i = matrix.size();
        int j = matrix[0].size();
        int l = 0;
        int r = i * j - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            int val = matrix[mid/j][mid%j];
            if(val == target){
                return true;
            }
            if(val < target){
                l = mid + 1;
            }
            if(val > target){
                r = mid - 1;
            }
        }



        return false;
    }
};
