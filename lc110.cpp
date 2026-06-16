#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int dfs(TreeNode* node) {
    if(!node) return 0;

    int lh = dfs(node->left);
    int rh = dfs(node->right);

    if((lh == -1 || rh == -1) || (abs(lh - rh) > 1)) {
        return -1;
    }
    else {
        return 1 + max(lh, rh);
    }
}
bool isBalanced(TreeNode* root) {
    return dfs(root) == -1 ? false : true;
}
