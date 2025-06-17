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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode* root, int maxSoFar){
        if(root==NULL) return 0;

        int countGoodNodes = 0;
        if(root->val >= maxSoFar){
            countGoodNodes=1;
            maxSoFar = root->val;
        }

        countGoodNodes += dfs(root->left, maxSoFar);
        countGoodNodes += dfs(root->right, maxSoFar);

        return countGoodNodes;
    }
};