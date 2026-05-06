class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int i = matrix.size();
        int j = matrix[0].size();

        int l = 0;
        int r = i * j - 1;

        while(l <= r){
            
            int m = (l + r) / 2;

            int row = m / j;
            int col = m % j;

            if(target < matrix[row][col]){
                r = m - 1;
            } else if(target > matrix[row][col]){
                l = m + 1;
            } else {return true;}
        }

        return false;


    }
};
