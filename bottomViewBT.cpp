#include <iostream>
#include <map>
using namespace std;

// Structure representing each node of the binary tree
struct Node {
    // Value stored in the node
    int data;
    // Pointer to the left child
    Node* left;
    // Pointer to the right child
    Node* right;
    // Constructor to initialize a node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Class containing the logic for top view
class Solution {
public:
    // Function to return the top view of the binary tree
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        map<int, int> colToVal;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, col] = q.front(); q.pop();
            colToVal[col] = node->data;
            if (node->left)  q.push({node->left,  col - 1});
            if (node->right) q.push({node->right, col + 1});
        }
        for (auto& [col, val] : colToVal) ans.push_back(val);
        return ans;
    }
};

// Driver code
int main() {
    // Create the sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    // Create a Solution object
    Solution solution;

    // Get the top view
    vector<int> result = solution.topView(root);

    // Print the top view traversal
    cout << "Top View Traversal: ";
    for (auto node : result) {
        cout << node << " ";
    }
    return 0;
}
