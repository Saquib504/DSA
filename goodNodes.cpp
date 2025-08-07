#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

int goodNodes(TreeNode*root){
    int good_nodes = 0;
    stack<pair<TreeNode*, int>> stk;
    stk.emplace(root, -10001);

    while(!stk.empty()){
        auto [node, curMax] = stk.top();
        stk.pop();
        
        if(!node)continue;
        good_nodes += node->val >= curMax;

        curMax = max(curMax, node->val);

        stk.emplace(node->left, curMax);
        stk.emplace(node->right, curMax);
    }
    return good_nodes;
}


int main(){
    ifstream file("goodNodes.txt");
    if(!file){
        cout << "Error: can't open file goodNodes.txt\n"; 
    }
}