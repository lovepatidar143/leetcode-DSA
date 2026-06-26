class Trie{
    public : 
    vector<Trie*> child ; 
    int val ; 

    Trie(){
        child.resize(2 , nullptr) ; 
        val  = INT_MAX ; 
    }

    // inserting 
    void insert(int x){
        Trie *cur = this ; 

        for(int i =31 ; i >= 0 ; i--){
            bool set = x & (1 << i) ; 
            if(!cur -> child[set]){
                cur -> child[set] = new Trie() ; 
            }
            cur -> val = min(cur -> val , x) ; 
            cur = cur -> child[set] ; 
        }
        cur -> val = min(cur -> val , x) ; 
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // insertion
        Trie trie ; 
        for(int num : nums) trie.insert(num) ; 
        // insettion is completed 
        vector <int> solution ; 

        for(auto it : queries){
            int el = it[0];
            int ml = it[1] ;
            int ans = -1 ; 
            Trie * cur = &trie ; 
            // int maxSetBit = log2(ml) ; 
            bool notFound = false ; 
            // bool canTake = false ; 
            for(int i = 31 ; i >=0 ; i--){
                if(cur -> val > ml){
                    notFound = true ; 
                    break ; 
                }

                // now we are in safe zone ... 
                bool bitSet = el & (1 << i) ;
                bool maxBitSet = ml & (1 << i)  ; 
                // now we do opposite 
                if(bitSet){
                    // bit is set find 0 
                    if(cur -> child[0] && cur -> child[0] -> val <= ml ){
                        // if(canTake)
                        cur = cur->child[0] ;
                    }else {
                        cur = cur -> child[1] ; 
                    }
                }
                else {

                    if(cur -> child[1] && cur -> child[1] -> val <= ml){
                        cur = cur -> child[1];
                    }
                    else {
                        cur = cur -> child[0] ; 
                    }
                }

            }

            if(!notFound) {
                ans = cur -> val ^ el ; 
            }

            solution.push_back(ans) ; 
            

            

        }
        return solution ; 
    }
};