#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int maxSum = -1e9;

int dfs(TreeNode* node) {
    if(!node) return 0;

    int left = dfs(node->left);
    int right = dfs(node->right);

    maxSum = max(maxSum, node->val + left + right);

    return node->val + max(left, right);
}

int maxPathSum(TreeNode* root)  {
    dfs(root);
    return maxSum;
}



int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int maxPath = maxPathSum(root);

    cout << "Max Path Sum : " << maxPath << endl;
    return 0;
}