class Solution {
public:
    bool isH(int paper , int pub){
        return pub <= paper ;
    }
    int hIndex(vector<int>& arr) {
        sort(arr.begin() , arr.end()) ; 
        int ans= 0; 
        int n = arr.size() ; 
        for(int i = 0 ; i< n ; i++){
            if(isH(arr[i] , n-i)) {
                ans = max(ans , n-i);
            }
        }
        return ans; 
    
    }
};