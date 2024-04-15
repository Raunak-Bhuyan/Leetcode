class Solution{
    public:
        int minDepth(TreeNode* root){
            if(!root)
                return 0;
            

            if(root->left == NULL && root->right == NULL)
                return 1;

            int L = root->left != NULL ? minDepth(root->left): INT_MAX;
            int r = root->right != NULL ? minDepth(root->right): INT_MAX;

            return 1+min(L,R); //Adding 1 because we are also considering the root node.
        }
}