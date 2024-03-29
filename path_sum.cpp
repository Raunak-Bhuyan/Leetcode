class Solution { //O(n) time,where n is no. of nodes //O(h) space
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) 
            return false;
        else if(root->val == targetSum && root->left == nullptr && root->right == nullptr) 
            return true;
       else{
           int newTarget = targetSum - root->val;
           return hasPathSum(root->left, newTarget) ||  hasPathSum(root->right, newTarget);
       }
    }
    
};