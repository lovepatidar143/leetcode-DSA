class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin() , arr.end()) ; 
        // int curel = 1 ; 
        int prev = 1; 
        int n =arr.size()  ; 
        // int ans = INT_MIN ; 
        // if(arr[0] != 1) arr
        for(int i = 1 ; i< n ; i++){
            if(arr[i] - prev <= 1){
                prev = arr[i] ; 
            }
            else {
                prev = prev +1 ; 
            }
        }
        return prev ; 
    }
};