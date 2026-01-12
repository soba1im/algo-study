#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, temp;
    cin >> N;
    
    vector<int> numArr;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        numArr.push_back(temp);
    }

    sort(numArr.begin(), numArr.end());

    for (int i = 0; i < N; i++) {
        cout << numArr[i] << "\n";
    }

    return 0;
}