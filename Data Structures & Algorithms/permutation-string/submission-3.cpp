class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;


        vector<int> seen(26, 0);
        vector<int> seen2(26,0);

        for(int i = 0; i < s1.length(); i++){
            seen[s1[i]-'a']++;
            seen2[s2[i]-'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++){
            if(seen[i] == seen2[i]){
                matches++;
            }
        }

        

        int l = 0;
        for(int r = s1.length(); r < s2.size(); r++){
            if(matches == 26){return true;}
            
            seen2[s2[r]-'a']++;
            if(seen[s2[r]-'a'] == seen2[s2[r]-'a']){matches++;}
            if (seen[s2[r]-'a'] + 1 == seen2[s2[r]-'a']){matches--;} 
            //originally matched, added too much
           
           seen2[s2[l]-'a']--;
            if(seen[s2[l]-'a'] == seen2[s2[l]-'a']){matches++;}
            if (seen[s2[l]-'a'] - 1 == seen2[s2[l]-'a']){matches--;} 
            //originally matched, removed a matching letter
            l++;
            
        }

        return matches == 26;

    }
};
