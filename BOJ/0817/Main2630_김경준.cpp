#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <cctype>
#include <sstream>
#pragma warning(disable:4996)

#define endl '\n';
#define all(x)
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define txtout freopen("output.txt", "w", stdout);
#define fst first
#define snd second

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int N, a, white = 0, blue = 0;
stringstream in;
vector<vector<bool>> v;

/**
 * BOJ 2630 색종이 : https://www.acmicpc.net/problem/2630
 * 전체 종이가 모두 같은 색으로 칠해져 있지 않으면 4등분 한다.
 * 위의 과정으로 잘라진 종이가 모두 같은 색으로 칠해져 있을때까지 반복
 *
 * 1. 주어진 정사각형(왼쪽 위 [x][y], 길이 N) 이 모두 같은 색으로 되어있는지 확인
 *    1.1 모두 같은색이라면?
 *         - 파란색 / 흰색 ++
 *    1.2 다른색이라면 -> 4등분 후 1. 과정 다시 반복
 *         -  1사분면 == x , y , N/2
 *         -  2사분면 == x, y + N/2 , N/2
 *         -  3사분면 == x + N/2, y, N/2
 *         -  4사분면 == x + N/2 , y + N/2 , N/2
 */

using namespace std;
bool check(int x, int y, int len) {
	bool flag = v[x][y];
	for (int i = x; i < x + len ; i++) {
		for (int j = y; j < y + len; j++) {
			if (flag != v[i][j]) return 0;
		}
	}
	return 1;
}
void solve(int x, int y, int len) {
	if (check(x, y, len)) { // 정사각형이면
		if (v[x][y]) blue++;
		else white++;
		return;
	}else {
		// 1,2,3,4 사분면 분할정복
		solve(x, y, len / 2);
		solve(x, y + len / 2, len / 2);
		solve(x + len / 2, y, len / 2);
		solve(x + len / 2, y + len / 2, len / 2);
	}
}

int main() {
	fastio;
	txtcin;
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<bool> temp;
		for (int j = 0; j < N; j++) {
			cin >> a;
			temp.push_back(a);
		}
		v.push_back(temp);
	}
	solve(0, 0, N);
	cout << white << "\n" << blue;
	return 0;
}
