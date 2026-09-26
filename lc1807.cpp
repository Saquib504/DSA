#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;


string evaluate(string s, vector<vector<string>>& knowledge) {
    int n = s.size();
    int m = knowledge.size();

    unordered_map<string, string> mpp;

    for(auto str : knowledge) {
        mpp.emplace(str[0], str[1]);
    }

    int idx = 0;
    string result = "";

    while(idx < n) {
        if(s[idx] == '(') {
            string temp = "";
            idx++;

            while(idx < n && s[idx] != ')') {
                temp += s[idx];
                idx++;
            }

            auto it = mpp.find(temp);
            result += (it != mpp.end() ? it->second : "?");
            idx++;
        }
        else {
            while(idx < n && s[idx] != '(') {
                result += s[idx];
                idx++;
            }
        }
    }

    return result;
}



int main() {
    string s;
    cout << "Enter the string : "; cin >> s;
    vector<vector<string>> knowledge;
    
    // Updated instruction for clarity
    cout << "Enter key-value pairs (Enter '-1' to stop):\n";
    while(true) {
        string key, value;
        if (!(cin >> key)) break;
        
        // Break out immediately if the key is "-1"
        if (key == "-1") break; 
        
        if (!(cin >> value)) break;

        knowledge.emplace_back(vector<string>{key, value});
    }

    cout << "The evaluated string is : " << evaluate(s, knowledge) << endl;
    return 0;
}
