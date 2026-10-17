class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector< pair<pair<int , int > , int>> arr ; 
        int n = nums.size() ;
        for(int i = 0 ; i<n ; i++){
            int it = nums[i];
            int pt = it  ;
            int sum = 0 ; 
            while(it){
                sum += it%10 ; 
                it = it/10 ; 
            }
            arr.push_back({{sum , pt} , i}) ; 
        }

        sort(arr.begin() , arr.end()) ; 
        int ans= 0 ; 
        // unordered_map <int, int > hash ; 
        // for(int i = 0 ; i< n ; i++) hash[nums[i]] = i ; 
        vector<int> visited(n , 0) ; 
        int cycle = 0 ; 
        for(int i = 0 ; i< n ; i++){
            if(!visited[i]) {
                visited[i] = 1 ; 
                cycle ++;
                int num = arr[i].second ;
                while(!visited[num]){
                    visited[num] = 1 ; 
                    num = arr[num].second ;
                }
            }
        }
        ans = n - cycle ; 
        return ans ; 
    }
};