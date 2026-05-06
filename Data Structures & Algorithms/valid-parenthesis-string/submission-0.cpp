class Solution {
public:
    bool checkValidString(string s) {
        //least, most
        int minL = 0;
        int maxL = 0;

        for(char c : s){
            
            if(c == '('){
                minL++;
                maxL++;
            } else if (c == ')'){
                minL--;
                maxL--;
            } else if (c == '*'){
                minL--;
                maxL++;
            }

            if(maxL < 0) return false;
            if(minL < 0) minL = 0;
        }

        return minL == 0;

    }
};
