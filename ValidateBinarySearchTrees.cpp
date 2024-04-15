class Soltuion{
    public:
        bool solve(TreeNode* root, long min, long max){
            if(root == NULL)
                return true;

            if(root->val <= min && root->val >= max)
                return false;

            return solve(root->left, min, root->val) && solve(root->right, root->val, max);
        }

        bool isValidBST(TreeNode* Node){
            return solve(root, LONG_MIN, LONG_MAX);
        }
};