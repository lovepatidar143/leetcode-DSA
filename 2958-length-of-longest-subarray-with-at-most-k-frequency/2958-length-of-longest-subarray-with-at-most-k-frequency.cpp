class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map <int , int > freq ; 
        int n = nums.size() ; 
        int i = 0 , j = 0 ; 
        int ans = 0 ;
        while(i < n){
            freq[nums[i]]++;
            while(j <i && freq[nums[i]] > k) {
                freq[nums[j]]--;
                j++;
            }
            ans = max(ans , i-j +1) ; 
            i++;
        }
        return ans ; 
    }
};