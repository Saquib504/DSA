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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> Q;

        Q.push({p,q});

        while(!Q.empty()) {
            auto [a, b] = Q.front();
            Q.pop();

            if(!a && !b) continue;

            if(!a || !b || a->val != b->val) return false;

            Q.push({a->left, b->left});
            Q.push({a->right, b->right});
        }

        return true;
    }
};