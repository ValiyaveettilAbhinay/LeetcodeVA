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

    pair<int, int> traverse(TreeNode *root,int &cnt){
        if(root == nullptr) return {0,0};

        auto [leftSum,leftCount] = traverse(root->left,cnt);
        auto [rightSum,rightCount] = traverse(root->right,cnt);

        int subTreeSum = leftSum + rightSum + root->val;
        int subTreeCount = leftCount + rightCount + 1;

        if(subTreeSum/subTreeCount == root->val) cnt++;

        return {subTreeSum,subTreeCount};

    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        traverse(root,count);
        return count;
    }
};