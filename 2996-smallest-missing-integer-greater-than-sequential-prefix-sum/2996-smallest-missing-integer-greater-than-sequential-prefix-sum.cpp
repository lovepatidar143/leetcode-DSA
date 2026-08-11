class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map <int , int > hash ; 
        int n = nums.size() ; 
        for(int i = 0 ; i< n ; i++) hash[nums[i]]++;
        int cnt = 1 , sum = nums[0] , finalSum = sum; 
        int maxi = cnt ; 
        for(int i = 1; i< n ; i++){
            if(nums[i] == nums[i-1] +1){
                // cnt += nums[i] ;
                cnt++;
                sum += nums[i] ; 
                finalSum = sum ; 
            }
            else {
                break ; 
                // cnt = nums[i] ; 
                cnt = 1 ; 
                sum = nums[i] ; 
            }
            // maxi = max(maxi , cnt) ; 
            if(cnt > maxi){
                finalSum = sum ; 
                maxi = cnt ; 
            }
        }
        for(int i = finalSum ; i< INT_MAX ; i++){
            if(hash.find(i) == hash.end()) return i ; 
        }
        return -1 ; 
    }
};