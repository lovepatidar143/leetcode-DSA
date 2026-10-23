class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ; 
        int ans = INT_MIN ; 
        int i = 0 , j = n-1 ; 
        while(i < j){
            int water = (j-i)*min(height[i] , height[j]) ; 
            ans = max(water , ans) ; 
            if(height[i] < height[j]) i++;
            else j--;
        }
        return ans ; 
    }
};