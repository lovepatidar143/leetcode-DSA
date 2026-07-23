class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size() ;
        if(n <= 2) return n ; 

        int ans  = (1 <<((int)floor(log2(n)) + 1)) ; 
        return ans ; 

    }
};
