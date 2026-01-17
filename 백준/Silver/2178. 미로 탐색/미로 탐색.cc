#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

int maze[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, x, y;
  string temp;
  queue<pair<int, int>> q;

  cin >> N >> M;

  for (int i = 0; i < N; i++) { // maze 생성
    cin >> temp;
    for (int j = 0; j < M; j++) {
      maze[i][j] = temp[j] - '0';
    }
  }

  q.push({0, 0});
  maze[0][0] = 1;
  while (!q.empty()) {

    auto [x, y] = q.front();
    q.pop();

    if ((x == N - 1) && (y == M - 1)) break; // 도착했을 때

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
      if ((nx != 0 || ny != 0) && maze[nx][ny] >= 2) continue;
      if (maze[nx][ny] == 0) continue;  

      maze[nx][ny] = maze[x][y] + 1;
      q.push({nx, ny});
    }
  }

  cout << maze[N - 1][M - 1];

  return 0;
}