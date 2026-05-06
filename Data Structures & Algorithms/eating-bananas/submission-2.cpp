class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        //rate

        //piles[i] max < rate < 1

        //piles[i] < k = 1
        //piles[i] > k = piles[i] / k 
        // (a + b - 1) / b == round up division


        //hrs > h
        int result = r;
        while(l <= r){
            int time = 0;
            int mid = l + (r - l) / 2;

            for(int p : piles){
                time += (p + mid - 1) / mid;
            }

            if(time <= h){//if time is valid
                result = mid; //eat rate
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        return result;
    }
};
