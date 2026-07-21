class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int MOD = 1e9 +7 ; 
        int n= nums.size() ; 
        vector<long long > pre(n , 0) ; 
        pre[0] = nums[0] ;
        for(int i = 1 ; i < n ; i++){
            pre[i] = nums[i] + pre[i-1] ;
        }

        vector<int> nse(n)  ; 
        vector<int> pse(n) ; 
        stack <int> st ; 
        for(int i = 0 ; i< n ; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop() ; 
            pse[i] = st.empty() ? -1 : st.top() ;
            st.push(i) ; 
        }
        st = stack<int> () ; 
        for(int i= n-1 ; i>= 0 ; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop() ; 

            nse[i] = st.empty() ? n : st.top() ; 
            st.push(i); 
        }
        long long ans = 1LL*INT_MIN ; 
        for(int i = 0 ; i< n ; i ++){
            int left = pse[i] +1  , right = nse[i]-1 ; 
            long long  sum ;
            if(left == 0) sum = pre[right] ; 
            else sum = pre[right]-pre[left-1] ; 


            ans = max(ans , 1LL*sum*nums[i]) ; 
        }
        long long  r = ans%MOD ; 
        return r ; 
    }
};