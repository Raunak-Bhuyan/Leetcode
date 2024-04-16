class Solution{
    private:
        int result;
    public:
        int sumNumbers(TreeNode* root){
            if(!root)
                return NULL;

            result = 0;
            findSum(root, result);
            return result;
        }
    private:
        void findSum(TreeNode* root, int val){
            int cuur = val*10 + root->val;
            if(root->left == NULL && root->right == NULL ){
                result += curr;
                return;
            }
            if(root->left != NULL) findSum(root->left, curr);
            if(root->right != NULL) findSum(root->right, curr);
        }
};