class Trie {
public:
    bool flag    ; 
    vector <Trie*> child ; 
    Trie() {
        flag = false ; 
        child.resize(26 , nullptr) ; 

    }
    
    void insert(string word) {
        // Trie * root = new Trie() ; 
        int n =word.size() ; 
        Trie * cur = this ; 
        for(int i = 0 ; i < n ; i++){
            int ind = word[i] - 'a' ; 
            if(!cur -> child[ind]){
                cur -> child[ind] = new Trie() ; 
            }
            cur = cur -> child[ind] ; 
        }
        cur -> flag = true ; 
    }
    
    bool search(string word) {
        int n =word.size() ; 
        Trie * cur = this ; 

        for(int i = 0 ; i< n ; i++){
            int ind = word[i] - 'a' ; 
            if(!cur -> child[ind] ) return false ; 
            cur = cur -> child[ind] ;
        }
        
        if(cur->flag) return true ; 
        return false ; 
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size() ; 

        Trie * cur = this ; 
        for(int i = 0 ; i< n ; i++){
            int ind = prefix[i] - 'a' ; 

            if(!cur -> child[ind]) return false ; 
            cur = cur -> child[ind] ;
        }
        return true ; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */