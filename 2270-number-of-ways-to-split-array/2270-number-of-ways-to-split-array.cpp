class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size() ; 
        vector<long long > prev( n , 0) ; 
        vector<long long > next( n , 0) ; 
        prev[0] = nums[0] ; 
        next[n-1]=nums[n-1] ; 
        for(int i = 1 ; i< n ; i++){
            prev[i] = 0LL + nums[i] + prev[i-1] ; 
            next[n-i-1] = 0LL + nums[n-1-i] + next[n-i] ;
        }
        int cnt = 0 ; 
        for(int i = 0 ; i< n-1 ; i++){
            if(prev[i] >= next[i+1]) cnt++;
        }
        return cnt ; 
    }
};