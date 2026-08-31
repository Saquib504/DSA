#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC -> O(M)
// SC -> O(M)
vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    ListNode* prev = head;
    ListNode* curr = head;
    int cnt = 0;
    curr = curr->next;
    cnt++;
    vector<int> pos;

    while(curr->next) {
        if((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val)) {
            pos.push_back(cnt);
        }
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    int minDist = INT_MAX;
    int maxDist = -1;
    int n = pos.size();
    if(n <= 1) return {-1, -1};
    
    maxDist = pos[n-1] - pos[0];

    for(int i = 1; i < n; i++) {
        minDist = min(minDist, pos[i] - pos[i-1]);
    }
    return {minDist, maxDist};
}

// TC -> O(M)
// SC -> O(1)
vector<int> nodesBetweenCriticalPointsOS(ListNode* head) {
    ListNode* prev = head;
    ListNode* curr = head;
    curr = curr->next;
    int cnt = 1;
    int firstPos = -1, lastPos = -1, prevPos = -1;
    int minDist = INT_MAX;
    

    while(curr->next) {
        bool isCritical = (curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val);
        if(isCritical) {
           if(firstPos == -1) {
            firstPos = cnt;
           } else {
            minDist = min(minDist, cnt - prevPos);
           }
           prevPos = cnt;
           lastPos = cnt;
        }
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if(firstPos == -1 || firstPos == lastPos) {
        return {-1, -1};
    }

    return {minDist, lastPos - firstPos};
}


int main() {
    ListNode* head; int h;
    cout << "Enter the head ListNode val: "; cin >> h;
    head = new ListNode(h);
    cout << "Enter the rest of the ListNode val: ";
    ListNode*temp = head;
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        temp->next = new ListNode(n);
        temp = temp->next;
    }

    vector<int> ans = nodesBetweenCriticalPoints(head);

    cout << "minDist : " << ans[0] << ", maxDist: " << ans[1] << endl;
    return 0;
}