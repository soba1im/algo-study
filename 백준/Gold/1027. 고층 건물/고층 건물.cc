#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

int height[51];
int cnt;
int ans = 0;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  int N;
  int temp;

  cin >> N;

  // 1. 빌딩 정보 입력 받기
  for (int i = 1; i <= N; i++) {
    cin >> temp;
    height[i] = temp;
  }

  // case 1) N이 1
  if (N == 1) {
    cout << N - 1;
    return 0;
  }

  for (int i = 1; i <= N; i++) {

    // 2. 좌우 따로
    cnt = 0;
    long long l_prev_n, l_prev_d;
    long long r_prev_n, r_prev_d;

    for (int j = i - 1; j > 0; j--) { // 좌
      long long n = height[j] - height[i];
      long long d = j - i;
      if (j == i - 1 || n * l_prev_d < l_prev_n * d) {
        cnt++;
        l_prev_n = n;
        l_prev_d = d;
      }
    }
    for (int j = i + 1; j <= N; j++) { // 우
      long long n = height[j] - height[i];
      long long d = j - i;
      if (j == i + 1 || n * r_prev_d > r_prev_n * d) {
        cnt++;
        r_prev_n = n;
        r_prev_d = d;
      }
    }
    if (ans < cnt)
      ans = cnt;
  }
  cout << ans;

  return 0;
}