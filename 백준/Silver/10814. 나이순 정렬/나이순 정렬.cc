#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    int N, ageTemp;
    string nameTemp;
    cin >> N;
    
    vector<pair<int, string>> info;

    for (int i = 0; i < N; i++) {
        cin >> ageTemp >> nameTemp;
        info.push_back({ageTemp, nameTemp});   
    }
    stable_sort(info.begin(), info.end(), cmp);

    for (int i = 0; i < N; i++) {
        cout << info[i].first << " " << info[i].second << "\n";
    }

    return 0;
}
