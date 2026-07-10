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


string serialize(Node* root) {
    if(!root) return "";
    string ans = "";
    queue<Node*> q;
    q.push(root);
    

    while(!q.empty()) {
        Node* curr = q.front(); q.pop();

        if(curr == NULL){
            ans.append("#,");
        }
        else {ans.append(to_string(curr->data)+',');}

        if(curr != NULL) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return ans;
}

// Decodes your encoded data to tree.
Node* deserialize(string data) {
    if(data.size() == 0) return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ',');

    Node* root = new Node(stoi(str));

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        auto curr = q.front();  q.pop();

        getline(s, str, ',');
        if(str == "#") {
            curr->left = NULL;
        }
        else {
            curr->left = new Node(stoi(str));
            q.push(curr->left);
        }

        getline(s,str,',');
        if(str == "#") {
            curr->right = NULL;
        }
        else {
            curr->right = new Node(stoi(str));
            q.push(curr->right);
        }
    }
    return root;
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
    
    cout << "The serialized string for the tree is: " << serialize(root) << endl;

    return 0;
}