#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> graph[101];
bool visited[101];

void dfs (int cur) {
  visited[cur] = 1;

  for (int next : graph[cur]) {
    if (!visited[next]) {
      dfs(next);
    }
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, tempA, tempB, count = 0; // N: 컴퓨터 수, M: 연결된 컴퓨터 쌍의 수

  cin >> N >> M;
  for (int i = 0; i < M; i++) { // 그래프 생성
    cin >> tempA >> tempB;
    graph[tempA].push_back(tempB);
    graph[tempB].push_back(tempA);
  }

  dfs(1);

  for (int i = 2; i <= N; i++) {
    if (visited[i])
      count++;
  }

  cout << count;

  return 0;
}