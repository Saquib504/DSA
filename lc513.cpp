#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


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


int findBottomLeftValue(Node* root) {
    int ans = -1;
    if(!root) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int sz = q.size();

        for(int i = 0; i < sz; i++) {
            auto node = q.front();
            q.pop();

            if(i == 0)
                ans = node->data;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }

    return ans;
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

    int ans = findBottomLeftValue(root);
    cout << "The bottom most element is : " << ans << endl;
    return 0;
}