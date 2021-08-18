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
struct charger {
	int x, y, c, p;
};
int T, mv, bc_num, a, answer, a_x, a_y, b_x, b_y;
vector<int> a_dir;
vector<int> b_dir;
vector<charger> chargers;
vector<pii> arr[11][11];
int dx[5] = { 0,-1,0,1,0 };
int dy[5] = { 0,0,1,0,-1 };
string s;
stringstream in;
void setting();
void init();
int solve();
bool oob(int, int);
void bfs(charger, int);

int main() {
	fastio;
	txtcin;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> mv >> bc_num;
		init();
		for (int i = 0; i < mv; i++) {
			cin >> a;
			a_dir.push_back(a);
		}
		for (int i = 0; i < mv; i++) {
			cin >> a;
			b_dir.push_back(a);
		}
		for (int i = 0; i < bc_num; i++) {
			int y, x, c, p;
			cin >> y >> x >> c >> p;
			charger temp = { x,y,c,p };
			chargers.push_back(temp);
		}
		setting();

		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				cout << arr[i][j].size()<<" ";
			}
			cout << endl;
		}
		
		int answer = 0;
		answer += solve();
		for (int i = 0; i < mv; i++) {
			a_x += dx[a_dir[i]];
			a_y += dy[a_dir[i]];
			b_x += dx[b_dir[i]];
			b_y += dy[b_dir[i]];
			answer += solve();
		}
		
		cout << "#" << tc << " " << answer << endl;
	}


	return 0;
}
void init() {
	a_x = a_y = 1;
	b_x = b_y = 10;
	a_dir.clear(); b_dir.clear();
	chargers.clear();
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			arr[i][j].clear();
}
int solve() {
	int sum = 0;
	int a_size = arr[a_x][a_y].size();
	int b_size = arr[b_x][b_y].size();
	if (a_size == 0) {
		for (int i = 0; i < b_size; i++)
			sum = max(sum, arr[b_x][b_y][i].fst);
	}else if (b_size == 0) {
		for (int i = 0; i < a_size; i++)
			sum = max(sum, arr[a_x][a_y][i].fst);
	}else {
		for (int i = 0; i < a_size; i++) {
			for (int j = 0; j < b_size; j++) {
				if (arr[a_x][a_y][i].snd == arr[b_x][b_y][j].snd)
					sum = max(sum, arr[a_x][a_y][i].fst);
				else 
					sum = max(sum, arr[a_x][a_y][i].fst + arr[b_x][b_y][j].fst);
			}
		}
	}
	return sum;
}
void setting() {
	for (int i = 0; i < bc_num; i++) {
		bfs(chargers[i], i);
	}
}
void bfs(charger bc, int bcNum) {
	queue<pii> q;
	bool visit[11][11] = { 0 };
	visit[bc.x][bc.y] = 1;
	arr[bc.x][bc.y].push_back({ bc.p,bcNum });
	q.push({ bc.x, bc.y });
	int cnt = 1;
	while (!q.empty()) {
		int size = q.size();
		while (size-- > 0) {
			auto [cur_x, cur_y] = q.front(); q.pop();
			for (int i = 0; i < 5; i++) {
				int nx = cur_x + dx[i];
				int ny = cur_y + dy[i];
				if (!oob(nx, ny) && !visit[nx][ny]) {
					visit[nx][ny] = true;
					arr[nx][ny].push_back({ bc.p, bcNum });
					q.push({ nx, ny });
				}
			}
		}
		if (cnt == bc.c) break;
		cnt++;
	}
}
bool oob(int x, int y) {
	return x < 1 || x >= 11 || y < 1 || y >= 11;
}
