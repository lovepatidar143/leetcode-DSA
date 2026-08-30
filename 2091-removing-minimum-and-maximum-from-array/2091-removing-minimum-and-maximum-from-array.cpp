class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = 0 ,  maxi = 0 ;  
        for(int i =1 ; i< nums.size() ; i++){
            if(nums[i] > nums[maxi]) maxi = i ; 
            if(nums[i] < nums[mini]) mini = i ; 
        }
        int n = nums.size() ;
        if(mini < maxi){
            int a = mini +1 +  n - maxi ; 
            int b = min(maxi +1 , n - mini) ; 
            return min(a , b) ; 

        }
        int a = maxi + 1 + n - mini ; 
        int b = min(mini +1 , n - maxi) ; 
        return min(a , b);
    }
};