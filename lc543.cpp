#include <iostream>
using namespace std;



int diameter = 0;
int dfs(TreeNode* node) {
    if(!node) return 0;

    int left = dfs(node->left);
    int right = dfs(node->right);

    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}
int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);

    return diameter;
}