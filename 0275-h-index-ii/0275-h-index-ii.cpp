class Solution {
public:
    bool isH(int citation , int paper){
        return paper <= citation ; 
    }
    int hIndex(vector<int>& citations) {
        int ans = 0 ; 
        int low = 0 , n = citations.size() ,high = n -1 ; 
        while(low <=high){
            int mid = low + (high-low)/2; 
            if(isH(citations[mid] , n-mid)){
                ans = n- mid ; 
                high = mid -1 ; 
            }
            else {
                low= mid +1  ; 
            }
        }
        return ans ; 

    }
};