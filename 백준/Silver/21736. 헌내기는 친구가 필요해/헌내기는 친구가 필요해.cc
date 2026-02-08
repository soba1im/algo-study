#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

char graph[600][600];
bool visited[600][600];
int dx[4] = {1, -1, 0, 0}; 
int dy[4] = {0, 0, 1, -1}; 
int people_N = 0;

void dfs(int n, int m, int x, int y) {
  visited[x][y] = true;

  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if (visited[nx][ny]) continue;
    if (graph[nx][ny] == 'X') continue;

    if (graph[nx][ny] == 'P') ++people_N;

    dfs(n, m, nx, ny);
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  /*
    O는 빈 공간, X는 벽, I는 도연이, P는 사람
    -> 최단 시간이나 거리를 구할 필요 X -> DFS 이용
  */

  /*
    개인적으로 느낀 이 문제의 가장 중요한 점
    : 
  */

  int N, M;
  string temp;
  pair<int, int> doyeon;

  cin >> N >> M;

  // 1. 입력 받은 문자열로 그래프 초기화 & 도연이 위치 기록해놓기
  for (int i = 0; i < N; i++) {
    cin >> temp;

    for (int j = 0; j < M; j++) {
      if (temp[j] == 'I') { // 도연 위치 기록
        doyeon = {i, j};
      }
      graph[i][j] = temp[j];
    }
  }

  // 2. DFS로 만난 인원 기록
  dfs(N, M, doyeon.first, doyeon.second);

  // 3. 인원 출력
  if (people_N == 0) cout << "TT";
  else cout << people_N;
  
  return 0;
}