#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct Node {
public:
    int val;
    Node* right;
    Node* left;          // Fixed: NOde → Node
    Node(int val) {
        this->val = val;
        right = left = nullptr;
    }
};

vector<int> zigzag(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);
    bool rightToLeft = true;  // first level: just root, then alternate

    while (!q.empty()) {
        int size = q.size();
        deque<int> level;

        for (int i = 0; i < size; i++) {
            Node* node = q.front(); q.pop();
            if (rightToLeft)
                level.push_back(node->val);   // L to R
            else
                level.push_front(node->val);  // R to L (reverse)

            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }

        for (int x : level) ans.push_back(x);
        rightToLeft = !rightToLeft;
    }
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = zigzag(root);
    cout << "The required order: ";
    for (auto x : ans) cout << x << " ";
    cout << endl;  // 1 3 2 4 5 6 7
}