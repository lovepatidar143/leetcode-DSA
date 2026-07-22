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
    int cnt = 0 ; 
    bool isleaf(TreeNode * node){
        return ( ! node-> left && !node-> right);
    }
    void dfs(TreeNode * node , int &mask){
        if(isleaf(node)){
            // check and update 
            mask^=(1<<node-> val);
            if(mask == 0 || __builtin_popcount(mask) == 1) cnt++;
            mask^=(1<<node-> val);
            return ;
        }
        int n= mask ; 
        mask ^= (1<< node->val) ;
        if(node -> left)dfs(node ->left , mask) ; 
        if(node -> right)dfs(node -> right , mask) ; 
        mask = n  ;


    }

    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0 ; 
        int mask = 0 ; 
        dfs(root ,mask ) ; 
        return cnt ;
    }
};