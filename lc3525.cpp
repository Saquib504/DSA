#include <iostream>
using namespace std;


constexpr int N=1<<18;

struct Node {
    int prod=1, freq[5]={0};

    inline void init(int x, int k) {
        prod=x;
        freq[0]=freq[1]=freq[2]=freq[3]=freq[4]=0;
        freq[x]=1;                  
    }

    inline void merge(const Node& L, const Node& R, int k) {
        int prod0=(L.prod*R.prod)%k;
        int f[5]={0};
        for (int i=0; i<k; i++) 
            f[i]=L.freq[i];
        for (int i=0; i<k; i++) {
            int r=(L.prod*i) % k;
            f[r]+=R.freq[i];
        }

        prod=prod0;
        for (int i=0; i<k; i++) 
            freq[i]=f[i];
    }
};

Node tree[N];

class SegTree {
public:
    int k;
    unsigned n, n2;

    SegTree(const vector<int>& nums, int k) : k(k), n(nums.size()) {
        n2=bit_ceil(n);

        for (int i=0; i<n; i++) {
            int v=nums[i] % k;
            tree[n2+i].init(v, k);
        }
        for (int i=n2-1; i>=1; i--) {
            tree[i].merge(tree[i<<1], tree[(i<<1)+1], k);
        }
    }

    void update(int idx, int x) {
        idx+=n2;
        tree[idx].init(x, k);

        for (idx>>=1; idx>= 1; idx>>=1) {
            tree[idx].merge(tree[idx<<1], tree[(idx<<1)+1], k);
        }
    }

    Node query(int l, int r) const {
        Node L, R;
        for (l+=n2, r+=n2; l<=r; l>>=1, r>>=1) {
            if (l & 1) L.merge(L, tree[l++], k);
            if ((r & 1)==0) R.merge(tree[r--], R, k);
        }
        L.merge(L, R, k);
        return L;
    }
};

 vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
    const int n=nums.size();
    SegTree seg(nums, k);
    const int qz=queries.size();
    
    vector<int> ans(qz);
    int i=0;
    for (auto& q : queries) {
        const int idx=q[0], v=q[1]%k, s=q[2], x=q[3];
        seg.update(idx, v);
        ans[i++]=seg.query(s, n-1).freq[x];
    }
    return ans;
}

int main() {
    vector<int> nums;
    int k;
    vector<vector<int>> queries;

    cout << "Enter Nums: ";
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        nums.push_back(n);
    }

    cout << "Enter k : "; cin >> k;
    
    cout << "Enter queries[indexi, valuei, starti, xi] : ";
    while(true) {
        int a, b, c, d;
        vector<int> temp(4);
        cin >> a >> b >> c >> d;
        if(a == -1 || b == -1 || c == -1 || d == -1)break;
        temp[0] = a;
        temp[1] = b;
        temp[2] = c;
        temp[3] = d;

        queries.push_back(temp);
    }

    vector<int> ans = resultArray(nums, k, queries);
    for(auto x : ans) {
        cout << x << " ";
    }cout<<endl;

    return 0;
}