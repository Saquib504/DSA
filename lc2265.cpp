#include <iostream>
using namespace std;


struct Node
{
    int val;
    Node* left;
    Node* right;
};


// Better Appraoch
// TC -> O(N)
// SC -> O(2)   ===> Using pair<int, int> for storing sum & n for returning in BFS;
using int2 = pair<int, int>;
int count = 0;

int2 inOrder(Node*root) {
    if(!root) return {0, 0};

    auto [sumL, nL] = inOrder(root->left);
    int sum = root->val, n = 1;
    auto [sumR, nR] = inOrder(root->right);

    sum += (sumL + sumR);
    n += (nL + nR);
    
    if(sum / n == root->val)count++;

    return {sum, n};
}

int averageOfSubtree(Node*root) {
    inOrder(root);
    return count;
}


// Optimal Approach
// TC -> O(N)
// SC -> O(1) + stack recursion space;  ===> Using unsigned long long 64bits for storing sum & n for returning in BFS(32bits for n, 32 bits for sum).

using u64 = unsigned long long;
int count = 0;

u64 inOrder(TreeNode*root) {
    if(root == NULL) return 0;
    u64 sum_L = inOrder(root->left);
    u64 sum = root->val + (1LL << 32);
    u64 sum_R = inOrder(root->right);
    sum += sum_L + sum_R;
    count += ((sum&0xffffffff)/(sum >> 32) == root->val);

    return sum;
}
int averageOfSubtree(TreeNode* root) {
    inOrder(root);
    return count;
}