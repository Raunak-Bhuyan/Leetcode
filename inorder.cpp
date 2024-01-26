class Solution{
    public:
        void solution(TreeNode* root, vector<int> &ans){
            if(!root) {
                return;
            }
            solution(root->left, ans);
            ans.push_back(root->val);
            solution(root->right, ans);
        }
        vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        solution(root, ans);
        return ans;
    }
};