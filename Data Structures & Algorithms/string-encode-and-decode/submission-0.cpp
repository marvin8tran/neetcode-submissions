class Solution {
public:


    string encode(vector<string>& strs) {
        string result;
        for(int i = 0; i < strs.size(); i++){
            result += to_string(strs[i].size()) + "#";
            result += strs[i];
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int j;
        int i = 0;
        while(j < s.size()){
            while(s[j] != '#'){j++;}

            int length = stoi(s.substr(i, j-i));

            string x = s.substr(j+1, length);
            result.push_back(x);
            j += length + 1;
            i = j;

        }


        return result;
    }
};
