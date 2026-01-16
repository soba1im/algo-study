#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <map>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[100][100];
bool visited[100][100];

void dfs(int N, int x, int y, int H) {
  visited[x][y] = true;

  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
    if (visited[nx][ny]) continue;
    if (board[nx][ny] - H <= 0) continue;

    dfs(N, nx, ny, H);
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, temp, maxH = 0, minH = 0;

  cin >> N;
  for (int i = 0; i < N; i++) { // board 생성
    for (int j = 0; j < N; j++) {
      cin >> temp;
      board[i][j] = temp;
    }
  }

  for (int i = 0; i < N; i++) { // 비 양의 최대/최솟값 찾기
    for (int j = 0; j < N; j++) {
      maxH = max(maxH, board[i][j]);
      minH = min(minH, board[i][j]);
    }
  }
  
  int cnt[maxH - minH];

  for (int i = minH; i < maxH; i++) { // dfs로 count가 최대인 값 찾기

    for (int j = 0; j < N; j++) { // visited 초기화
      for (int k = 0; k < N; k++) {
        visited[j][k] = false;
      }
    }
    temp = 0;

    for (int j = 0; j < N; j++) { // dfs 실행
      for (int k = 0; k < N; k++) {
        if (!visited[j][k] && board[j][k] - i > 0) {
          dfs(N, j, k, i);
          temp++;
        }
      }
    }
    
    cnt[i - minH] = temp;
  }

  sort(cnt, cnt + maxH - minH, greater<int>()); // 내림차순
  
  cout << cnt[0];

  return 0;
}