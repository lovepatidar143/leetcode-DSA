class Trie{
    public : 
    vector<Trie *> child ; 
    int val ; 
    //constructor
    Trie(){
        child.resize(2 , nullptr) ; 
        val = 0  ; 
    }

    void insert(int x ){
        Trie * cur = this ; 
        for(int i = 31 ; i >= 0 ; i--){
            int ind = ((x & (1 << i)) > 0 ); 
            if(!cur -> child[ind]){
                cur -> child[ind] = new Trie() ; 
            }
            cur = cur -> child[ind] ; 
        }
        cur -> val = x ; 
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie ; 
        for(int num : nums) trie.insert(num) ; 

        int ans = 0 ; 

        for(int num : nums){
            // do somethisng and change the ans ;;;;; maximise it 
            Trie * cur = &trie ; 
            // int x = 0 ; 
            
            for(int i = 31 ; i>= 0 ; i--){
                bool bitSet = num & (1 << i)  ; 
                if(bitSet){
                    // find 0 
                    if(cur -> child[0]){
                        // if we find the zero ... 
                        cur = cur -> child[0] ; 
                    }
                    else {
                        //there is no zero ... 
                        cur = cur -> child[1] ; 
                        // x += (2<<i) ; 
                    }
                }
                else {
                    // bit is not set find 1 
                    if(cur -> child[1]){
                        // yehh we ifind the one 
                        cur = cur -> child[1] ;
                        // x +=  (2<<i) ;  
                    }
                    else {
                        // cant find 1 so go to 0
                        cur = cur -> child[0] ; 
                    }
                }
            }

            // we reached at zeroth bit ... what is the no?? 
                ans = max(ans ,( (cur -> val )^ num )) ; 

        }
        return ans ; 
    }
};