class Solution {
public:
    string smallestSubsequence(string s) {
        stack <char > st ; 
        int n = s.size() ; 
        vector<int> freq(26 ,0) ; 
        for(auto ch : s) freq[ch -'a']++ ;
        
        // st.push(s[0]) ; 
        vector<int> take(26 , 0);
        for(int i = 0 ; i< n ; i++){
            char ch = s[i] ; 
            freq[ch -'a']--;
            if(take[ch -'a']) continue ;
            while(!st.empty() && st.top() > ch && freq[st.top() -'a'] > 0){
                take[st.top() -'a'] = 0 ;
                cout << "pop -> " << st.top() << endl;
                st.pop() ; 
            }
            if(!take[ch -'a']){
                st.push(ch) ;           
                cout << "push -> " << ch << endl ; 
                take[ch-'a'] =1;
            }

        }
        string ans = "" ; 
        while(!st.empty()){
            ans += st.top() ; 
            st.pop() ;
        }
        reverse(ans.begin() , ans.end()) ; 
        return ans ;
    }
};