#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int tomato[1000][1000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  /*
    
  */

  /*
    개인적으로 느낀 이 문제의 가장 중요한 점
    : 
  */

  int M, N;
  int temp, x, y, max_n;
  queue<pair<int, int>> q;

  cin >> M >> N;

  // 1. 토마토 그래프 생성 & 익은 토마토는 미리 큐에 넣기 -> 나중에 동시에 BFS를 실행해야 하므로
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> temp;
      tomato[i][j] = temp;

      if (tomato[i][j] == 1) { // 익은 토마토는 큐에 넣기
        q.push({i, j});
      }
    }
  }

  // 2. 동시 BFS 실행으로 토마토 그래프에 익은 날짜 업데이트
  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
      if (tomato[nx][ny] != 0) continue;

      q.push({nx, ny});
      tomato[nx][ny] = tomato[x][y] + 1;
    }
  }

  // 3. 정답 출력
  max_n = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      max_n = max(max_n, tomato[i][j]);
    }
  }

  // 3-1. 안 익은 토마토가 존재하는 경우
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (tomato[i][j] == 0) {
        cout << -1;
        return 0;
      }
    }
  }

  // 3-2. 저장될 때부터 모든 토마토가 익어있는 경우
  if (max_n == 1) {
    cout << 0;
    return 0;
  }

  // 3-3. 이외의 일반적인 경우
  cout << max_n - 1;

  
  return 0;
}