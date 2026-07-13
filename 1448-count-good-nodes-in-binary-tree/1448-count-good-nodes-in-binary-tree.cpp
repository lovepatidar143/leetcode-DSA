/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0 ; 
        if(!root) return cnt ; 
        stack <pair < TreeNode *  , int >> st ; 
        st.push({root , INT_MIN}) ;
        while(!st.empty()){
            TreeNode * node = st.top().first ; 
            int prev = st.top().second ; 
            st.pop(); 


            // do your work 

            if(node -> val >= prev) cnt++ ; 
            // push the remailnig 
            if(node -> left){
                st.push({node -> left , max(prev , node -> val)}) ; 
            }
            if(node -> right){
                st.push({node -> right , max(prev , node -> val)}) ; 
            }
        }
        return cnt ; 
    }
};