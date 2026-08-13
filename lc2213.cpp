#include <iostream>
#include <string>
#include <vector>
using namespace std;



struct Node {
    int pre = 0; 
    int suf = 0;
    int maxLen = 0;
    char leftChar = 0;
    char rightChar = 0;
};

int n;
vector<Node> segTree; //segmen tree size 4*n

Node merge(const Node& L, const Node& R, int leftLen, int rightLen) {
    Node res;

    res.leftChar  = L.leftChar;
    res.rightChar = R.rightChar;

    res.pre = L.pre;
    if (L.pre == leftLen && L.rightChar == R.leftChar) {
        res.pre = L.pre + R.pre;
    }

    res.suf = R.suf;
    if (R.suf == rightLen && L.rightChar == R.leftChar) {
        res.suf = R.suf + L.suf;
    }

    res.maxLen = max(L.maxLen, R.maxLen);
    if (L.rightChar == R.leftChar) {
        res.maxLen = max(res.maxLen, L.suf + R.pre);
    }

    return res;
}

void buildSegmentTree(int i, int l, int r, string& s) {
    if (l == r) {
        segTree[i] = { 1, 1, 1, s[l], s[l] };
        return;
    }
    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, s);
    buildSegmentTree(2 * i + 2, mid + 1, r, s);
    segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
}

void update(int i, int l, int r, int pos, char ch) {
    if (l == r) { //l == r == pos
        segTree[i] = { 1, 1, 1, ch, ch };
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos <= mid) {
        update(2 * i + 1, l, mid, pos, ch);
    } else {
        update(2 * i + 2, mid + 1, r, pos, ch);
    }
    segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
}

vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
    n = s.size();
    segTree.assign(4 * n, Node()); //segmen tree size 4*n

    buildSegmentTree(0, 0, n - 1, s);

    int k = queryIndices.size();

    vector<int> result(k);
    for (int i = 0; i < k; i++) {
        int pos = queryIndices[i];
        char ch = queryCharacters[i];
        update(0, 0, n - 1, pos, ch);
        
        result[i] = segTree[0].maxLen; //root node covers entire string
    }

    return result;
}

int main() {
    string s, queryCharacters;
    vector<int> queryIndices;

    cout << "Enter the string s: "; cin >> s;
    cout << "\nEnter the queryCharacters: "; cin >> queryCharacters;
    cout << "\nEnter the query indices one by one and enter -1 to stop: "; 
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        else queryIndices.push_back(n);
    }

    vector<int> ans = longestRepeating(s,queryCharacters, queryIndices);

    for(auto x : ans) {
        cout << x << " ";
    }cout<<endl;


    return 0;
}


/*

Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
Output: [3,3,4]
Explanation: 
- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2nd query updates s = "bbbccc". 
  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].

*/