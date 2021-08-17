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
int N, a, b;
stringstream in;

/**
 * 정보올림피아드 1828 냉장고
 * 특정 냉장고로 가장 많은 화학 원소를 커버하기 위해서는 여러개의 화학 원소의 온도 범위 중 겹치는 가장 좁은 범위 안의 온도로 설정할 때이다.
 * 
 * 기존에 설정된 범위 안쪽으로 들어온다는 것은 한대의 냉장고로 처리가 가능하다는 뜻이다.
 * 
 * 이 때 가장 좁은 범위로 축소시키기 위해  최저 온도가 증가하면 냉장고의 최저 온도 범위를 증가시키고,
 * 최고 온도가 감소하면 냉장고의 최고 온도 범위도 맞춰서 감소시켜가며 냉장고의 온도 범위를 세팅한다.
 * 
 * 만약 화학 원소가 해당 범위에 들어오지 못한다면 새로운 냉장고가 필요하다는 뜻이고, count를 증가시킨다. 
 */

using namespace std;
int main() {
	fastio;
	txtcin;
	vector<pii> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());  // 최저온도 -> 최고온도 기준 sorting
	int left = v[0].fst;  // 초기 범위 설정
	int right = v[0].snd;
	int cnt = 1;
	for (auto [fst, snd] : v) {
		if (fst <= right) {              // 기존 범위 안쪽에 들어오는 경우
			left = fst;                    // 최소온도 재설정
			if (right > snd) right = snd;  // 최대온도 재설정
		}
		else {                           // 기존 범위 바깥 -> 새 냉장고 필요 
			left = fst;                    // 온도 범위 재설정
			right = snd;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
