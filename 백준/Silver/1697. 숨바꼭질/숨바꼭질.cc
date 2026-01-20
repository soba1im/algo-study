#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <map>
#include <queue>
#include <tuple>
using namespace std;

int visited[100001];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K, X, X_sec;
  queue<pair<int, int>> q;

  cin >> N >> K;

  q.push({N, 0}); // 수빈이의 처음 위치
  visited[N] = true;
  while (!q.empty()) {
    // ++sec; <- 이 방법은 올바르게 구하지 못함. 따라서 밑에 있는 if문 만족 시 push를 할 때 일일히 저장하는 방법으로
    X = q.front().first;
    X_sec = q.front().second;
    q.pop();

    if (X == K) { // 수빈이가 동생을 찾았다면 -> 종료
      break;
    }

    if (X - 1 >= 0 && !visited[X - 1]) { // 조건 순서가 매우 중요 *** : 경계 먼저 체크 필요 ***
      visited[X - 1] = true;
      q.push({X - 1, X_sec + 1});
    }

    if (X + 1 <= 100000 && !visited[X + 1]) {
      visited[X + 1] = true;
      q.push({X + 1, X_sec + 1});
    }

    if (2 * X <= 100000 && !visited[2 * X]) {
      visited[2 * X] = true;
      q.push({2 * X, X_sec + 1});
    }
  }

  cout << X_sec;

  return 0;
}