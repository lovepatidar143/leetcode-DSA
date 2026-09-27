class Solution {

public:

    string reverseParentheses(string s) {

        stack<string> st;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch != ')') {
                st.push(string(1, ch));
            }
            else {
             string t = "";
                while(!st.empty() && st.top() != "(") {
                    string temp = st.top();
                    reverse(temp.begin() ,temp.end()) ; 
                    t += temp ; 
                    st.pop();

                }        
                st.pop();
                st.push(t);

            }

        }

        string ans = "";

        while(!st.empty()) {
            ans = st.top() + ans;
           st.pop();
        }
        return ans;

    }

};