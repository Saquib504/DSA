#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};


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