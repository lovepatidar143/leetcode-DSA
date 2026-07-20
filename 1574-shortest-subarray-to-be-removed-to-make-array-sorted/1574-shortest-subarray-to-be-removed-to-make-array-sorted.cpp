class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size() ; 
        int left = 0 , right = n-1 ; 
        while(left < n-1 && arr[left] <= arr[left+1]) left++;
        while(right >0 && arr[right] >= arr[right-1]) right--;
        if(left == n-1) return 0 ; 
        int i = 0 , j = right , len , ans =min(n - left -1  , right) ; 

        while(i <= left && j < n){
            if(arr[i] <= arr[j]){
                ans = min(ans , j-i-1) ; 
                i++;

            }
            else {
                j++;
            }
        }
        return ans ; 

    }
};