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
int N, a;
string s;
stringstream in;
vector<vector<int>> v;

/**
 * BOJ 1992 쿼드 트리 : https://www.acmicpc.net/problem/1992
 * 색종이 문제에서 괄호만 추가
 * 
 */

using namespace std;
bool check(int x, int y, int len) {
	int flag = v[x][y];
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (flag != v[i][j]) return 0;
		}
	}
	return 1;
}
void solve(int x, int y, int len) {
	if (check(x, y, len)) { // 정사각형이면
		cout << v[x][y];
		return;
	}
	else {
		// 1,2,3,4 사분면 분할정복
		cout << "(";
		solve(x, y, len / 2);
		solve(x, y + len / 2, len / 2);
		solve(x + len / 2, y, len / 2);
		solve(x + len / 2, y + len / 2, len / 2);
		cout << ")";
	}
}

int main() {
	fastio;
	txtcin;
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		cin >> s;
		for (int j = 0; j < N; j++) {
			temp.push_back(s[j]-'0');
		}
		v.push_back(temp);
	}
	solve(0, 0, N);
	return 0;
}
