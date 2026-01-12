#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int N, M, temp;
    vector<int> Narr, Marr, ans;

    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> temp;
      Narr.push_back(temp);
    }
    sort(Narr.begin(), Narr.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
      cin >> temp;
      Marr.push_back(temp);

      if (binary_search(Narr.begin(), Narr.end(), Marr[i])) {
        ans.push_back(1);
      }
      else {
        ans.push_back(0);
      }
    }

    for (int i = 0; i < M; i++) {
      cout << ans[i] << "\n";
    }
    
    return 0;
}