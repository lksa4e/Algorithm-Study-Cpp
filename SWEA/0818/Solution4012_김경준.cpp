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
int T,N, a, answer;
string s;
stringstream in;
int arr[16][16];
vector<int> idn;
void solve();
int main() {
	fastio;
	txtcin;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> a;
				arr[i][j] = a;
			}
		}
		answer = 1e9;
		idn.clear();
		for (int i = 0; i < N / 2; i++) idn.push_back(0);
		for (int i = 0; i < N / 2; i++) idn.push_back(1);
		do {
			solve();
		} while (next_permutation(idn.begin(), idn.end()));
		cout << "#" << tc << " " << answer << endl;
	}
	

	return 0;
}
void solve() {
	int fst = 0, snd = 0;
	for (int i = 0; i < N; i++) {  // 1과 같은그룹 , 2와 같은그룹,,,
		if (idn[i] == 1) {
			for (int j = 0; j < N; j++)
				if (i != j && idn[j] == 1) fst += arr[i][j];
		}else {
			for (int j = 0; j < N; j++)
				if (i != j && idn[j] == 0) snd += arr[i][j];
		}
	}
	int num = abs((fst - snd));
	answer = min(answer, num);
}
