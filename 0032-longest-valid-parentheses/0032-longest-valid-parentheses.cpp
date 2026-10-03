class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0 ; 
        int len = 0 , prev = 0; 
        // bool bar = false ;
        stack <int> st ; 
        st.push(-1);
        for(int i = 0 ; i< s.size() ; i++){
            char ch = s[i] ; 
            if(ch == '('){
                // bar = false ; 
                st.push(i) ; 
            }
            else {
                st.pop(); 
                if(st.empty()) {
                    // prev = 0 ; 
                    st.push(i) ; 
                }
                else {
                    ans = max(ans , i - st.top()) ; 
                }
            }
                   
        }

        return ans ; 
    }
};