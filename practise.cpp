#include <iostream>
using namespace std;


int main() {
    vector<string> words = {"apple", "banana", "strawberry", "kiwi", "grape"};

    auto it = max_element(words.begin(), words.end(),
                          [](const string &a, const string &b) {
                              return a.size() < b.size();
                          });

    cout << "Max element: " << *it << endl;
}