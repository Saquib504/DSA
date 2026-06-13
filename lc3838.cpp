#include <iostream>
#include <vector>
#include <string>
using namespace std;


string mapWordWeights(vector<string>& words, vector<int>& weights) {
    int n = words.size();
    string ans = "";

    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = 0; j < words[i].size(); j++) {
            sum += weights[words[i][j] - 'a'];
        }

        sum = sum % 26;
        ans += 'z' - sum;
    }

    return ans;
}



int main() {
    int n, w;
    cout << "Enter the number of words and the number of weights: "; 
    cin >> n >> w;

    vector<string> words;
    vector<int> weights;
    cout << "Enter the words: " << endl;
    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    cout << "\nNow enter the weights in a line : ";
    for(int i = 0; i < w; i++) {
        int weight; cin >> weight;
        weights.push_back(weight);
    }

    cout << "\nThe resultant string is: " << mapWordWeights(words, weights)<< endl;
    return 0;
}