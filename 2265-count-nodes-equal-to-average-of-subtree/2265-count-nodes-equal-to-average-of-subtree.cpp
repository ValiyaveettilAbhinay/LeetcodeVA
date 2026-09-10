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
    int ans = 0;

    pair<int, int> traverse(TreeNode *root){
        if(root == nullptr) return {0,0};

        auto [leftSum,leftCount] = traverse(root->left);
        auto [rightSum,rightCount] = traverse(root->right);

        int subTreeSum = leftSum + rightSum + root->val;
        int subTreeCount = leftCount + rightCount + 1;

        if(subTreeSum/subTreeCount == root->val) ans++;

        return {subTreeSum,subTreeCount};

    }

    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return ans;
    }
};