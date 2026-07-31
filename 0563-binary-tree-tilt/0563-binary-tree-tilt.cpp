/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int calc(TreeNode* node) {
        if (node == NULL)
            return 0;

        int leftSum = calc(node->left);
        int rightSum = calc(node->right);

        ans += abs(leftSum - rightSum);
        return leftSum + rightSum + node->val;
    }

    int findTilt(TreeNode* root) {
        calc(root);
        return ans;
    }
};