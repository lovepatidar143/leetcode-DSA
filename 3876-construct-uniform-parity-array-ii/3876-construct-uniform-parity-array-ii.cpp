class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
      bool alleven = true ;
        int mini = INT_MAX ;
    int n = nums1.size();
        for(int i = 0 ; i<n; i++){
            if(nums1[i]%2==1) alleven = false;
            mini = min(mini,nums1[i]);
        }
        if(mini %2 ==1) return true;
        else if(alleven) return true;
        return false;
    }
};