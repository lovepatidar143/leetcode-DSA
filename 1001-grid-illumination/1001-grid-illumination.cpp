class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
 
        // vector<int> row(n , 0)  , col(n ,0) , diag(2*n -1 , 0) , antiDiag(2*n -1 , 0); 
        unordered_map <int , int > row , col , diag , antiDiag ; 
        map < vector<int> , int > hash ;   
        for(auto it : lamps){
            if(hash.find(it) != hash.end()) continue ; 
            hash[it]++;
            int r = it[0] ;
            int c = it[1] ; 
            int d = r - c + n -1 ; 
            // if(row[r] && col[c] && diag[d] && antiDiag[r+c]) continue ;
            row[r] +=1 ; 
            col[c] += 1 ; 
            diag[d] +=1 ; 
            antiDiag[r+c]++;
        }

        int q = queries.size() ; 
        vector<int> ans ; 
        // map < vector<int> , int > hash2 ; 
        for(auto it : queries){
            int a ; 
            int r = it[0] , c = it[1] , d = r-c + n -1 ;
            if(row[r] || col[c] || diag[d] || antiDiag[r+c]){
                a = 1 ; 

                for(int i = r -1 ; i <= r +1 ; i++ ){
                    for(int j = c-1 ; j<= c+1 ; j++){
                        if(i  < n && j < n && i >=0 && j >= 0 ){
                            if(hash.find({i,j}) != hash.end()){
                                row[i]--;
                                col[j]--;
                                diag[i-j + n-1]--;
                                antiDiag[i+j]--;
                                hash.erase({i,j}) ;
                            }
                            // if(hash2.find({i , j}) != hash2.end()) a = 0 ; 
                        }
                    }
                }



            }
            else {
                a = 0 ; 
            }

            ans.push_back(a) ; 
        }

        return ans ; 
    }
};