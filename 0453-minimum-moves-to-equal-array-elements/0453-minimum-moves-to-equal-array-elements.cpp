class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ; 
        int x = nums[0] ; 
        int ans = 0 ; 
        for(auto it : nums) ans += (it - x) ; 
        return ans ; 
    }
};