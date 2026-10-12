class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0 ; 
        int i =1 ; 
        int n = nums.size() ; 
        for(auto it : nums){
            if(n%i == 0) ans += (it *it) ; 
            i++;
        }
        return ans ; 
    }
};