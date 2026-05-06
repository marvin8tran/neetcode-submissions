class Solution {
public:
    unordered_map<int, vector<char>> keymap;
    //int, letters

    vector<string> letterCombinations(string digits) {
    if(digits.empty()) return {};
        keymap[2] = {'a', 'b', 'c'};
        keymap[3] = {'d', 'e', 'f'};
        keymap[4] = {'g', 'h', 'i'};
        keymap[5] = {'j', 'k', 'l'};
        keymap[6] = {'m', 'n', 'o'};
        keymap[7] = {'p', 'q', 'r', 's'};
        keymap[8] = {'t', 'u', 'v'};
        keymap[9] = {'w', 'x', 'y', 'z'};
        vector<string> res;
        string subset;
        bt(0, digits, subset, res);
        return res;
    }
    
    void bt(int idx, string& digits, string& subset, vector<string>& res){
        if(idx == digits.size()){
            res.push_back(subset);
            return;
        }

        //for every char num could be
        for(char n : keymap[digits[idx] - '0']){
            subset.push_back(n);
            bt(idx+1, digits, subset, res);
            subset.pop_back();
        }
        return;
    }
};
