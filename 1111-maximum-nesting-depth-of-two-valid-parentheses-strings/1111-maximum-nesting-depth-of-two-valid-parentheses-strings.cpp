class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack <char> st1 , st2 ; 
        int n = seq.size() ; 
        vector<int> ans(n , 0) ; 
        for(int i = 0 ; i< n ; i++){
            char ch = seq[i] ; 
            if(ch == '('){
                if(st1.size() < st2.size()){
                    ans[i] = 0 ; 
                    st1.push(ch) ; 
                }
                else {
                    ans[i] = 1 ; 
                    st2.push(ch) ;
                }
            }else {
                if(st1.size() > st2.size()){
                    ans[i] = 0 ; 
                    st1.pop();
                }
                else {
                    ans[i] = 1 ; 
                    st2.pop(); 
                }
            }
        }
        return ans ; 
    }
};