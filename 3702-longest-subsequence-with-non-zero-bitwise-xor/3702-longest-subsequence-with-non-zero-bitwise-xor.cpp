class Solution {
public:
    
    int longestSubsequence(vector<int>& nums) {
        bool allzero = true; 
        int xor1 = 0 ; 
        for(auto it: nums){
            if(it != 0) allzero = false ; 
            xor1 = xor1 ^ it ; 
        }
        int n = nums.size() ; 
        if(xor1 != 0) return n ; 
        if(allzero) return 0 ;
        return n-1 ;  
    }
};