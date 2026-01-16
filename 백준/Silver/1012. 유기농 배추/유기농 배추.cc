#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[50][50];
bool visited[50][50];

void dfs (int x, int y, int M, int N) {
  visited[x][y] = true;

  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
    if (visited[nx][ny]) continue;
    if (board[nx][ny] == 0) continue;

    dfs(nx, ny, M, N);
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T, M, N, K, tempX, tempY, count;

  cin >> T;

  for (int i = 0; i < T; i++) { // 각 테스트 케이스에 대해
    cin >> M >> N >> K;

    for (int u = 0; u < 50; u++){
      for (int v = 0; v < 50; v++) {
        board[u][v] = 0; 
        visited[u][v] = false;
      }
    }
    /* memset(visited, false, sizeof(visited));
    memset(board, 0, sizeof(board)); */ // visited & board 초기화가 중요 포인트였음 ***
    for (int j = 0; j < K; j++) { // 배추 표시
      cin >> tempX >> tempY;
      board[tempX][tempY] = 1;
    }

    count = 0;

    for (int k = 0; k < M; k++) {
      for (int l = 0; l < N; l++) {
        if (!visited[k][l] && board[k][l] != 0) {
          dfs(k, l, M, N);
          count++;
        }
      }
    }

    cout << count << "\n";
  }

  return 0;
}