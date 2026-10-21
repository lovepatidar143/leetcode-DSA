class Solution {
public:
    bool solve(vector<int> &arr , long long  x , int d ){
        long long  last = arr[0] ; 
        for(int i= 1 ; i< arr.size() ; i++){
            long long  newEle= last + x ; 
            if(newEle > arr[i]+d) return false ; 
            last = max(newEle , 1LL*arr[i]);
        }
        return true ; 
    }
    int maxPossibleScore(vector<int>& start, int d) {
        int ans = -1  ; 
        long long  low = 0 , n = start.size(); 
        sort(start.begin() , start.end()) ; 
        long long  high =  start[n-1]+d;

        while(low <= high){
            long long  mid = low + (high -low)/2 ; 
            if(solve(start , mid , d)){
                ans = mid ; 
                low = mid+1 ; 
            }
            else {
                high = mid -1; 
            }
        }
        return ans ;
    }
};