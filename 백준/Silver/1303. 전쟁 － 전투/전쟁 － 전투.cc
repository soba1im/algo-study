#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char graph[100][100];
bool visited[100][100];
// 궁금한 점: 아래 선언한 자료들은 전역이 좋을까, 지역이 좋을까?
int W_comp[100000]; // 내 병사
int B_comp[100000]; // 적군 병사

void dfs(int N, int M, int count, int x, int y, char WorB) {

  visited[x][y] = true; // 1. 방문 처리
  // 2. 컴포넌트 번호, 병사 수 기록
  if (WorB == 'W') { // 아군 DFS이면
    W_comp[count - 1]++;
  }
  else { // 적군 DFS이면
    B_comp[count - 1]++;
  }

  for (int dir = 0; dir < 4; dir++) { // 3. 상하좌우가 조건 만족 -> dfs 실행
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
    if (visited[nx][ny]) continue;
    if (graph[nx][ny] != WorB) continue;

    dfs(N, M, count, nx, ny, WorB);
  }

}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  /*
    내 병사: W, 적국 병사: B 

    출력: (W / B 따로) 각 component를 이루는 병사 수^2의 합

    -> 최단 거리를 구할 필요X -> DFS 이용이 효율적!!!
  */

  /*
    개인적으로 느낀 이 문제의 가장 중요한 점
    : component number와 그 구성 병사의 수를 기록할 자료구조의 선택
  */

  int N, M;
  int W_count = 0, B_count = 0;
  int W_hap = 0, B_hap = 0;
  string temp;

  cin >> N >> M;

  // 1. 입력받은 것으로 그래프 초기화
  for (int i = 0; i < M; i++) { 
    cin >> temp;
    for (int j = 0; j < N; j++) {
      graph[i][j] = temp[j];
    }
  }

  // 2. DFS로 component 번호 & 그 component를 이루는 내 병사의 수 기록
  for (int i = 0; i < M; i++) { 
    for (int j = 0; j < N; j++) {
      if (graph[i][j] == 'W' && !visited[i][j]) {
        ++W_count;
        dfs(N, M, W_count, i, j, 'W');
      }
    }
  }

  // 3. DFS로 component 번호 & 그 component를 이루는 적군 병사의 수 기록
  for (int i = 0; i < M; i++) { 
    for (int j = 0; j < N; j++) {
      if (graph[i][j] == 'B' && !visited[i][j]) {
        ++B_count;
        dfs(N, M, B_count, i, j, 'B');
      }
    }
  }

  // 4-1. 아군 병사 위력의 합 구하기
  for (int i = 0; i < W_count; i++) {
    W_hap += W_comp[i] * W_comp[i];
  }
  // 4-2. 적군 병사 위력의 합 구하기
  for (int i = 0; i < B_count; i++) {
    B_hap += B_comp[i] * B_comp[i];
  }

  // 5. 답 출력
  cout << W_hap << " " << B_hap;
  
  return 0;
}