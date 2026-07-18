#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
#include <algorithm>
#include <climits>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class NodeValue {
public:
    int minValue, maxValue, maxSum;
    bool isBST;

    NodeValue(int minValue, int maxValue, int maxSum, bool isBST) {
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->maxSum = maxSum;
        this->isBST = isBST;
    }
};

int globalMaxSum = 0; // Tracks the absolute maximum sum seen so far

NodeValue helper(Node* root) {
    // Base case: An empty tree is a valid BST with a sum of 0
    if (!root) {
        return NodeValue(INT_MAX, INT_MIN, 0, true);
    }

    // Post-order traversal: Get info from subtrees first
    auto left = helper(root->left);
    auto right = helper(root->right);

    // A node is a valid BST if both subtrees are BSTs AND the current value
    // fits strictly between the left subtree's max and right subtree's min.
    if (left.isBST && right.isBST && root->data > left.maxValue && root->data < right.minValue) {
        int currentSum = root->data + left.maxSum + right.maxSum;
        globalMaxSum = std::max(globalMaxSum, currentSum);
        
        // Pass up the true min and max boundaries for this new valid BST
        return NodeValue(
            std::min(root->data, left.minValue),
            std::max(root->data, right.maxValue),
            currentSum,
            true
        );
    }

    // If it's not a valid BST, pass up invalid markers so parent nodes fail validation
    return NodeValue(INT_MIN, INT_MAX, 0, false);
}

int maxSumBST(Node* root) {
    globalMaxSum = 0; // Reset for each test case
    helper(root);
    return globalMaxSum;
}

// Inserts a node by following a path of L/R moves measured from the ROOT.
// The path describes the moves from the root to the NEW node itself.
// Example: value=2, path={L,L,R,L} means: from root go Left, Left, Right,
// and the new node becomes the LEFT child of the node you land on.
// All moves except the last one must lead to an already-existing node.
bool insertNode(Node* root, int value, const vector<char>& path) {
    if (path.empty()) {
        cout << "Error: empty path given.\n";
        return false;
    }

    Node* current = root;
    // Walk to the parent of the new node (every move except the last one)
    for (size_t i = 0; i + 1 < path.size(); i++) {
        current = (path[i] == 'L') ? current->left : current->right;
        if (current == nullptr) {
            cout << "Error: path is invalid, an intermediate node is missing.\n";
            return false;
        }
    }

    char lastMove = path.back();
    Node* newNode = new Node(value);

    if (lastMove == 'L') {
        if (current->left != nullptr) {
            cout << "Warning: left child already existed, it has been replaced.\n";
            delete current->left;
        }
        current->left = newNode;
    } else {
        if (current->right != nullptr) {
            cout << "Warning: right child already existed, it has been replaced.\n";
            delete current->right;
        }
        current->right = newNode;
    }
    return true;
}

// Prints the tree rotated 90 degrees (root on the left) so the shape is easy to read.
void printTree(Node* root, int depth = 0) {
    if (root == nullptr) return;
    printTree(root->right, depth + 1);
    cout << string(depth * 6, ' ') << root->data << "\n";
    printTree(root->left, depth + 1);
}

int main() {
    int n;
    cout << "Enter the total number of nodes in the tree: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of nodes must be at least 1.\n";
        return 0;
    }

    int rootVal;
    cout << "Enter the value of the ROOT node: ";
    cin >> rootVal;
    Node* root = new Node(rootVal);

    cin.ignore(); // flush the leftover newline so getline works cleanly

    int remaining = n - 1;
    cout << "\nNow enter the remaining " << remaining << " node(s).\n";
    cout << "Format: <value> <move1> <move2> ... <moveK>\n";
    cout << "Each move is L (left) or R (right), measured from the ROOT.\n";
    cout << "Example: 2 L L R L  -> places value 2 by going Left, Left, Right, Left from the root.\n\n";

    for (int i = 0; i < remaining; i++) {
        cout << "Node " << (i + 2) << "/" << n << " -> ";
        string line;
        getline(cin, line);

        stringstream ss(line);
        int value;
        if (!(ss >> value)) {
            cout << "Could not read a value, please try again.\n";
            i--;
            continue;
        }

        vector<char> path;
        string token;
        bool badToken = false;
        while (ss >> token) {
            char move = toupper(token[0]);
            if (move != 'L' && move != 'R') {
                cout << "Invalid move '" << token << "', please re-enter this node.\n";
                badToken = true;
                break;
            }
            path.push_back(move);
        }

        if (badToken || path.empty()) {
            i--; // retry this same node
            continue;
        }

        if (!insertNode(root, value, path)) {
            i--; // retry this same node since insertion failed
        }
    }

    cout << "\n--- Tree built successfully! ---\n";
    cout << "\nSideways view (root on the left, top branch = right child):\n";
    printTree(root);

    cout << "The maximum sum of the valid BST in the given tree is : " << maxSumBST(root) << endl;


    return 0;
}