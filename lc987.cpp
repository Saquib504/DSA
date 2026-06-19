#include <iostream>
#include <set>
#include<map> 
using namespace std;

// This structure defines a node in the binary tree
struct Node {
    // This stores the value of the node
    int data;
    // Pointer to the left child
    Node* left;
    // Pointer to the right child
    Node* right;

    // Constructor initializes node with value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform vertical order traversal
vector<vector<int>> findVertical(Node* root) {
    if(!root) return {};
    vector<tuple<int, int, int>> nodes;

    queue<pair<Node*, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.second.first;
        int y = p.second.second;
        Node* node = p.first;

        nodes.push_back({x, y, node->data});

        if(node->left) {
            q.push({node->left, {x-1, y+1}});
        }
        if(node->right) {
            q.push({node->right, {x+1, y+1}});
        }
    }

    vector<vector<int>> ans;

    sort(nodes.begin(), nodes.end(), [](const auto &a, const auto &b) {
        if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        if(get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
        return get<2>(a) < get<2>(b);
    });

    int n = nodes.size();
    int i = 0;

    while(i < n) {
        vector<int> col;
        int j = i;

        while(j < n && get<0>(nodes[j]) == get<0>(nodes[i])) {
            col.push_back(get<2>(nodes[j]));
            j++;
        }
        ans.push_back(col);
        i = j;
    }

    return ans;
}

// Helper function to print result
void printResult(const vector<vector<int>>& result) {
    for (auto level : result) {
        for (auto node : level) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Driver code
int main() {
    // Create sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);


    // Call vertical order traversal
    vector<vector<int>> verticalTraversal = findVertical(root);

    // Print result
    cout << "Vertical Traversal:" << endl;
    printResult(verticalTraversal);

    return 0;
}
