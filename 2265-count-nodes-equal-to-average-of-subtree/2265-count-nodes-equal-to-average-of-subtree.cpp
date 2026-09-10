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
struct Node{
    int len ; 
    int sum ; 

};
class Solution {
public:

    int ans = 0 ; 
    Node solve(TreeNode * cur){
        if(!cur){
            Node state ; 
            state.len = 0 ;
            state.sum = 0 ; 
            return state ;   
        }
        Node leftstate , rightstate , curstate ; 
        leftstate = solve(cur->left) ; 
        rightstate = solve(cur -> right) ; 
        curstate.len = 1 + leftstate.len + rightstate.len ; 
        curstate.sum = cur -> val + leftstate.sum + rightstate.sum ; 
        if(curstate.sum / curstate.len == cur->val) ans++;
        return curstate ; 
    }    
    int averageOfSubtree(TreeNode* root) {
        Node state ; 
        state = solve(root) ;
        return ans ; 
    }
};