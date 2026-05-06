class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        bool c = false;
        
        for(int i = n; i >= 0; i--){
            if(i == n || c){
                digits[i]++; 
                c = false;  
            }
            if(digits[i] == 10){
                c = true;
                digits[i] = 0;
            }
        }

        if(c){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
