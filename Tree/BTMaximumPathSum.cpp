int solve(TreeNode* root,int& maxSum){
        if(root==NULL){
            return 0;
        }

        int left = max(0,solve(root->left,maxSum));
        int right = max(0,solve(root->right,maxSum));

        int currSum = root->val + left + right;

        maxSum = max(currSum,maxSum);

        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        solve(root,maxSum);

        return maxSum;
    }