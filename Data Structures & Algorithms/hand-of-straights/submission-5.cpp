class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> freq;
        for(int x : hand){
            freq[x]++;
        }

        sort(hand.begin(), hand.end());
        for(int n : hand){
            if(freq[n] > 0){
                for(int i = n; i < n + groupSize; i++){
                    if(freq[i] == 0) return false;
                    freq[i]--;
                }
            }
            
        }

        return true;


    }
};
