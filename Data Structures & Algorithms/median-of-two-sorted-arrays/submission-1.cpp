class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     if(nums1.size() > nums2.size()){return findMedianSortedArrays(nums2, nums1);}   

    auto A = nums1;
    auto B = nums2;

    int total = A.size() + B.size(); // rounded up half


    int l = 0;
    int r = nums1.size();

    while(l <= r){
        int i = (l+r)/2; //rounds down, doesnt include middle
        int j = (total + 1) / 2 - i;
        // Aleft = A[i - 1] = biggest left A
        // Aright = A[i] = smallest right A
        // Bleft = B[j - 1] = smallest right B
        // Bright = B[j] = biggest left B

        int Aleft = i > 0 ?  A[i-1] : INT_MIN;
        int Aright = i < A.size() ? A[i] : INT_MAX;
        int Bleft = j > 0 ?  B[j-1] : INT_MIN;
        int Bright = j < B.size() ? B[j] : INT_MAX;

        if(Aleft <= Bright && Bleft <= Aright){
            if(total % 2 != 0){
                return max(Aleft, Bleft);
            }
            
            return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
         } else if (Bright < Aleft){
            // A - 1 6 7 8  l = 0 r = 8 mid/i = 6 
            // B - 1 2 3 4 5 9
            // Aleft = 6, Bright = 4, 4 < 6


            r = i - 1; // r -> 6 so B can get more (j - i)
         } else{
            // A - 1 2 3 4 , l = 0 r = 4
            // B - 1 5 6 8 
            //Aright < Bleft (3 < 5)

            //1 2 3 4, mid(i) = 2
            //shift left to 2, so new is 3 4
            l = i + 1; //1 2 from mid left half -> 3 4 
         }


    }
    


        return 0.0;


    }
};
