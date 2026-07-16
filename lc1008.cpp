#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


Node* build(vector<int>& preorder, int& i, int bound) {
    if(i == preorder.size() || preorder[i] > bound) {
        return nullptr;
    }

    Node* root = new Node(preorder[i++]);

    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, bound);

    return root;
}
Node* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}

void printTree(Node* root, int depth = 0) {
    if (root == nullptr) return;
    printTree(root->right, depth + 1);
    cout << string(depth * 6, ' ') << root->data << "\n";
    printTree(root->left, depth + 1);
}


int main() {
    vector<int> preorder;
    cout << "Enter the node values of BST in preorder: ";
    while(true) {
        int n; cin >> n;
        if(n == -1)break;
        else preorder.push_back(n);
    }

    Node* root = bstFromPreorder(preorder);
    printTree(root);
    return 0;
}
