#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

/* 
int city[51][51]; // 도시 정보 저장
vector<pair<int, int>> chicken; // 치킨집 위치 저장
vector<pair<int, int>> house; // 집 위치 저장
vector<pair<int, int>> choose; // 조합된 치킨집
int result = 0;

void dfs(int M, int depth, int first) {
  int hap = 0;

  if (depth == M) { // 개수를 다 뽑았으면
    for (int i = 0; i < house.size(); i++) { // 각각의 집에서 최소인 치킨집 거리를 구하고 합 구하기
      int short_d = 0;
      for (int j = 0; j < choose.size(); j++) {
        int d = abs(house[i].first - choose[j].first) + abs(house[i].second - choose[j].second);
        short_d = min(short_d, d);
      }
      hap += short_d;
    }
    result = min(result, hap); // 가장 작은 경우 구함
  }

  for (int i = first; i < chicken.size(); i++) {
    choose.push_back({chicken[i].first, chicken[i].second});
    dfs(M, depth + 1, first + 1);
    choose.pop_back();
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  //  0은 빈 칸, 1은 집, 2는 치킨집

  int N, M;
  int temp;

  cin >> N >> M;

  // 1. 도시 정보 저장
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> temp;
      if (temp == 1) {
        house.push_back({i, j});
      }
      else if (temp == 2) {
        chicken.push_back({i, j});
      }
    }
  }

  // 조합으로 해서 다 구하고 가장 작은 값 선택
  dfs(M, 0, 0);
  
  cout << result;
  
  return 0;
}
*/

int city[51][51]; // 도시 정보 저장
pair<int, int> chicken[13]; // 치킨집 위치 저장
pair<int, int> house[2500]; // 집 위치 저장
pair<int, int> choose[13]; // 조합된 치킨집
int result = INT_MAX;

void dfs(int M, int depth, int first, int house_n, int chicken_n) {
  int hap = 0;

  if (depth == M) { // 개수를 다 뽑았으면
    for (int i = 0; i < house_n; i++) { // 각각의 집에서 최소인 치킨집 거리를 구하고 합 구하기
      int short_d = INT_MAX;
      for (int j = 0; j < M; j++) {
        int d = abs(house[i].first - choose[j].first) + abs(house[i].second - choose[j].second);
        short_d = min(short_d, d);
      }
      hap += short_d;
    }
    result = min(result, hap); // 가장 작은 경우 구함
    return;
  }

  for (int i = first; i < chicken_n; i++) {
    choose[depth] = {chicken[i].first, chicken[i].second};
    dfs(M, depth + 1, i + 1, house_n, chicken_n);
    choose[depth] = {-1, -1};
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  //  0은 빈 칸, 1은 집, 2는 치킨집

  int N, M;
  int temp, chicken_n = 0, house_n = 0;

  cin >> N >> M;

  // 1. 도시 정보 저장
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> temp;
      if (temp == 1) {
        house[house_n++] = {i, j};
      }
      else if (temp == 2) {
        chicken[chicken_n++] = {i, j};
      }
    }
  }

  // 조합으로 해서 다 구하고 가장 작은 값 선택
  dfs(M, 0, 0, house_n, chicken_n);
  
  cout << result;
  
  return 0;
}