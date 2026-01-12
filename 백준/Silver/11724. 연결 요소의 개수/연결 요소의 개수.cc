#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

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

  int N, M, u, v, count; // N: 정점 수, M: 간선 수

  cin >> N >> M;
  for (int i = 0; i < M; i++) { // 그래프 생성
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  count = 0;
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      dfs(i);
      count++;
    }
  }

  cout << count;

  return 0;
}