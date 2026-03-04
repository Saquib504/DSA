#include <iostream>
using namespace std;

class StockSpanner {
public:
    stack<pair<int ,int >> stk;
    StockSpanner() = default;
    
    int next(int price) {
        int span = 1;
        int ans = 1;

        while(!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner spanner;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for(int price : prices) {
        cout << spanner.next(price) << " ";
    }
    cout << endl;
    return 0;
}