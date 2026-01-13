#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[26][26];
bool visited[26][26];

void dfs (int x, int y, int N, int mk) {
  visited[x][y] = true;
  board[x][y] = mk;
  
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir]; 
    int ny = y + dy[dir];

    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
    if (visited[nx][ny]) continue;
    if (board[nx][ny] == 0) continue;

    dfs(nx, ny, N, mk);
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, mark = 0;
  string temp;
  cin >> N;

  for (int i = 0; i < N; i++) { // 지도 생성
    cin >> temp;
    for (int j = 0; j < N; j++) {
      board[i][j] = 0 - '0' + temp[j]; // 자료형이 매우 중요한 문제였음 ***
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j] && board[i][j] != 0) {
        ++mark;
        dfs(i, j, N, mark);
      }
    }
  }
  /* 출력
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  } */

  cout << mark << "\n";

  vector<int> count(mark);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] != 0) {
        count[board[i][j] - 1]++;
      }
    }
  }

  sort(count.begin(), count.end());
  for (int i = 0; i < mark; i++) {
    cout << count[i] << "\n";
  }

  return 0;
}