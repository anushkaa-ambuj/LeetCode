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
        dfs(root, INT_MIN);
        return countGoodNodes;
    }

private:
    int countGoodNodes = 0;
    void dfs(TreeNode* root, int maxSoFar){
        if(root==NULL) return;

        if(root->val >= maxSoFar){
            countGoodNodes++;
            maxSoFar = root->val;
        }

        dfs(root->left, maxSoFar);
        dfs(root->right, maxSoFar);
    }
};