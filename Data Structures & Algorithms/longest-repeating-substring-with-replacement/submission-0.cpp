class Solution {
public:
    int characterReplacement(string s, int k) {
        //window condition = k+1 different chars
        //

        unordered_map<char, int> seen;
        // 
        int res = 0;
        int l = 0;
        //cant do size cuz some might be dupes
        int maxFreq = 0; //# of biggest char?
        for(int r = 0; r < s.size(); r++){

            seen[s[r]]++;
            maxFreq = max(maxFreq, seen[s[r]]);

            while(r - l + 1 - maxFreq > k){
                seen[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);


        }

        return res;

    }
};
