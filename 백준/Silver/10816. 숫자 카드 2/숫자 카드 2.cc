#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int N, M, temp;
    vector<int> Narr, Marr, ans;
    vector<int>::iterator UB, LB;;

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
      UB = upper_bound(Narr.begin(), Narr.end(), Marr[i]);
      LB = lower_bound(Narr.begin(), Narr.end(), Marr[i]);


      if (LB == Narr.end() || *LB != Marr[i]) // LB 미존재
        ans.push_back(0);
      else // UB 존재 & 미존재
        ans.push_back(UB - LB);
    }

    for (int i = 0; i < M; i++) {
      cout << ans[i] << " ";
    }
    return 0;
}