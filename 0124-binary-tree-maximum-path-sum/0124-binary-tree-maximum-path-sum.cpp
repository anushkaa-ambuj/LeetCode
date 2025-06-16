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
    int maxPathSum(TreeNode* root) {
        maxPathDown(root);
        return ans;
    }

private:
    int ans=INT_MIN;

    int maxPathDown(TreeNode* node){
        if(!node) return 0;

        int leftSum = max(0, maxPathDown(node->left));
        int rightSum = max(0, maxPathDown(node->right));

        ans = max(ans, leftSum + rightSum + node->val);

        return max(leftSum, rightSum) + node->val;
    }
};