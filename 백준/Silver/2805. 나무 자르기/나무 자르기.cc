#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
  int N, M, temp;
  long long least = 0, mid, most, hap;
  vector<int> treeLength;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> temp;
    treeLength.push_back(temp);
  }
  sort(treeLength.begin(), treeLength.end());

  most = treeLength[N - 1] - 1;
  while (least < most){
    mid = (least + most) / 2 + 1;
    hap = 0;
    for (int i = 0; i < N; i++) {
      if (mid <= treeLength[i])
        hap += treeLength[i] - mid;
    }

    if (hap >= (long long)M)
      least = mid;
    else
      most = mid - 1;
  }

  cout << most;

  return 0;
}