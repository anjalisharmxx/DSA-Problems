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
    int findd(vector<int>& inorder,int left,int right, int val){
        for(int i=left;i<=right;i++){
           if( inorder[i]==val){
            return i;
           }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index,int left,int right){
        if(left>right) return NULL;

        TreeNode* root= new TreeNode(preorder[index]);

        int idx=findd(inorder,left,right,preorder[index]);
        index++;

        root->left=solve(preorder,inorder,index,left,idx-1);
        root->right=solve(preorder,inorder,index,idx+1,right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return solve(preorder,inorder,index,0,inorder.size()-1);
    }
};