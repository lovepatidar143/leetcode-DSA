class Solution {
public:
    vector <string> solution ; 
    void solve(int n , string s , int open , int close ){
        if(s.size() == 2*n){
            
            solution.push_back(s);
            
            return ;
        }
        if(close > open ) return ;

        if(open < n){
            solve(n ,  s + '(' , open +1 , close );
        }
        if(close < n ){
            solve(n ,s + ')', open , close +1);
        }

    }
    vector<string> generateParenthesis(int n) {
        solve( n , "" , 0 ,0);
        return solution ; 
    }
};