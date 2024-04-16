class Solution{
    public:

        int pathSum_a(TreeNode* root. long sum){
            if(!root)
                return 0;
            long paths = 0;
            if(root->val == sum) paths++;
            paths += pathSum_a(root->left, sum-root->val);
            paths += pathSum_a(root->right, sum-root->val);
            return paths;

        }
        int pathSum(TreeNode* root, long sum){
            if(!root)
                return 0;

            return pathSum(root->left, sum) + pathSum_a(root, sum) 
            + pathSum(root->right, sum);
        }
};