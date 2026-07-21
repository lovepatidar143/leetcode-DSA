class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7 ; 
        int n = arr.size() ;
        vector <int > pse(n , -1 ) ; 
        vector  <int> nse(n , n) ; 
        stack <int> st; 
        for(int i = 0 ;  i< n ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop() ; 
            pse[i] = st.empty() ? -1 : st.top() ; 
            st.push(i) ; 
        }
        st = stack<int>() ; 
        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop() ; 
            nse[i] = st.empty() ? n : st.top() ; 
            st.push(i) ; 
        }
            

        int ans = 0 ; 

        for(int i = 0 ; i< n ; i++){

            long long  val = (i - pse[i])*(nse[i] - i) ; 
            long long  take = (1LL*arr[i]*val)%MOD; 
            ans = (ans + take)%MOD; 
        }
        return ans ; 
    }
};