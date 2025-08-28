#include <iostream>
using namespace std;

struct Node {
    Node*links[2];
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node*get(int bit) {
        return links[bit];
    }
};

class Trie {
    Node*root;
    public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node*node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) &1;
            
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int findMax(int num) {
        Node*node = root;
        int maxXOR = 0;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(1 - bit)) {
                maxXOR = maxXOR | (1 << i);
                node = node->get(1 - bit);
            }
            else node = node->get(bit);
        }
        return maxXOR;
    }
};


vector<int> maxXORQueries(vector<int>&arr, vector<vector<int>>&queries) {
    int n = arr.size();
    int m = queries.size();
    vector<int> ans(m, 0);
    vector<pair<int, pair<int, int>>> offlineQueries;
    sort(arr.begin(), arr.end());

    for(int i = 0; i < m; i++) {
        offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());

    Trie trie;
    int index = 0;

    for(auto it : offlineQueries) {
        while(index < n && arr[index] <= it.first) {
            trie.insert(arr[index]);
            index++;
        }
        
        if(index != 0)
            ans[it.second.second] = trie.findMax(it.second.first);
        else 
            ans[it.second.second] = -1;
    }
    return ans;
}




int main() {
    vector<int> arr = {0,1,2,3,4}; 
    cout << "Given Array: ";
    for(int i =0; i< arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    vector<vector<int>> queries = {{3,1}, {1,3}, {5,6}};
    
    cout << "Queries: ";
    for(auto query: queries){
       cout << query[0] << " " << query[1] << ", ";
    }
    cout << endl;
    
    vector<int> result = maxXORQueries(arr, queries);

    cout << "Result of Max XOR Queries:" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "Query " << i+1 << ": " << result[i] << endl;
    }

    return 0;
}
