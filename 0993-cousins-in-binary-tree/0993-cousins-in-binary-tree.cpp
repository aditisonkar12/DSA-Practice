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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL)
            return false;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            bool foundX = false;
            bool foundY = false;

            while (sz--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->val == x)
                    foundX = true;
                if (node->val == y)
                    foundY = true;

                if (node->left && node->right) {
                    int l = node->left->val;
                    int r = node->right->val;

                    if ((l == x && r == y) || (l == y && r == x))
                        return false;
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (foundX && foundY)
                return true;
            if (foundX || foundY)
                return false;
        }
        return false;
    }
};