class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ; 
        vector<int> ans ; 
        int i = 1 ; 
        int n = nums.size() ; 
        int prev = nums[0] ; 
        while(i < n){
            if(prev +1 == nums[i]){
                prev = nums[i] ; 
                i++;
            }
            else {
                prev++;
                ans.push_back(prev) ; 
            }
        }
        return ans ; 
    }
};