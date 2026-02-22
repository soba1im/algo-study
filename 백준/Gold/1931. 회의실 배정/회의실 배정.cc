#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

pair<int, int> time[100000];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  int N;
  int s, e;
  int cnt = 0, end_t = 0;

  cin >> N;

  // 1. 회의 시간 입력받기
  for (int i = 0; i < N; i++) {
    cin >> s >> e;
    time[i] = {s, e};
  }

  // 2. 회의 끝나는 시간 기준 오름차순 정렬
  sort(time, time + N, [](pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
  });

  // 3. 최대 회의 개수 구하기
  for (int i = 0; i < N; i++) {
    if (time[i].first >= end_t) { // 이전 회의 끝난 시간 이후라면 가능
        cnt++;
        end_t = time[i].second;
    }
  }

  cout << cnt;

  return 0;
}