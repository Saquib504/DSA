#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* makeLL(vector<int>values) {
    int n = values.size();
    ListNode* head = new ListNode(values[0]);
    ListNode* temp = head;
    for(int i = 1; i < n; i++) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }
    return head;
}

int pairSum(ListNode* head) {
    int sum = INT_MIN;
    int n = 1;
    ListNode* temp = head;
    int i = 0;
    int N;

    //find the total number of elements first
    while(temp->next) {
        temp = temp->next;
        n++;
    }

    //then precompute the first half table to memoize the values
    N = (n/2) - 1;
    int halfSum[N+1];
    temp = head;
    i = 0;
    while(i <= N) {
        halfSum[i++] = temp->val;
        temp = temp->next;
    }
    
    i--;    //reset the i to it's original position

    //run a loop from n/2 to n in order to get the max sum
    while(temp) {
        sum = max(sum, halfSum[i--] + temp->val);
        temp = temp->next;
    }

    return sum;
}


int main() {
    vector<int> values;
    cout << "Enter all the elements that you want to include into the Linked List: ";
    int n;

    while(true) {
        int n;
        cin >> n;
        if(n == -1) break;
        values.push_back(n);
    }

    ListNode* head = makeLL(values);

    int sum = pairSum(head);
    cout << "The max pair sum is: " << sum << endl;
    return 0;
}