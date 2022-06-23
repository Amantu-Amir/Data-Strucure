class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* Min, TreeNode* Max){
        if(!root){
            return true;;
        }
        if(Max!=NULL and Max->val<=root->val){
            return false;
        }
        if(Min!=NULL and Min->val>=root->val){
            return false;
        }
        return dfs(root->left, Min, root) and dfs(root->right, root, Max);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, NULL, NULL);
    }
};


