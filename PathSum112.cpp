#include <iostream>
using namespace std;

bool hasPathSum(TrreeNode* root, int targetSum) {
    if(root  === nullptr) return false;

    if(!root->left && !root->right) {
        return targetSum == root->val;
    }

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}