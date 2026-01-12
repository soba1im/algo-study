#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
  int K, N;
  int lengthTemp;
  long long hap, lower = 0, upper = 0, mid = 0;
  vector<int> lengthList;

  cin >> K >> N;
  for (int i = 0; i < K; i++)
  { // 랜선의 길이 저장
    cin >> lengthTemp;
    lengthList.push_back(lengthTemp);
  }
  sort(lengthList.begin(), lengthList.end());

  lower = 1;
  upper = lengthList[K-1];

  while (lower < upper)
  {
    mid = (lower + upper) / 2 + 1;
    hap = 0;
    for (int i = 0; i < K; i++) {
      hap += lengthList[i] / mid;
    }
    if (hap >= N) {
      lower = mid;
    }
    else
      upper = mid - 1;
  }
  // 중간 -> 맞으면 그 위 범위, 아니면 그 아래 범위

  /*
    범위 : 1 <= 정답 <= 요소 / N의 합
  */

  cout << upper;

  return 0;
}