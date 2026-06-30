#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
#include <map>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int data) : val(data), left(nullptr), right(nullptr) {}
};


Node* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int>& inMap) {
    if(preEnd < preStart) return NULL;

    Node* root = new Node(preorder[preStart]);

    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart+1,preStart+numsLeft, inorder, inStart, inRoot-1, inMap);
    root->right = buildTree(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);

    return root;
}
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> inMap;

    for(int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    Node* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);

    return root;
}

void printTree(Node* root) {
    if(!root) {
        cout << "Binary Tree is not found" << endl;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int sz = q.size();
        cout<<endl;
        for(int i = 0; i < sz; i++) {
            auto node = q.front();  q.pop();

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);


            cout << node->val << " ";
        }
    }
}

int main() {
    int n; cout << "\nEnter the number of elements: ";
    cin >> n;
    vector<int> preorder(n), inorder(n);

    cout << "Enter the preOrder: ";
    for(int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    cout << "Enter the inOrder: ";
    for(int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    Node* root = buildTree(preorder, inorder);

    printTree(root);

    return 0;
}