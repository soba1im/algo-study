#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int N, x, y;
    vector<pair<int, int>> pArr;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
	    cin >> x >> y;
	    pArr.push_back({x, y});
    }
    
    sort(pArr.begin(), pArr.end());

		for (int i = 0; i < N; i++) {
	    cout << pArr[i].first << " " << pArr[i].second << "\n";
    }
    
    return 0;
}