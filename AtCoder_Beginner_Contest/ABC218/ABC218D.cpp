#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

typedef struct Point {
	int x, y;
} point;

int Judge(point& a, point& b, map<int, set<int>> &d) {
	return a.x != b.x && a.y != b.y && d[a.x].count(b.y) && d[b.x].count(a.y);
}

int main(void) {
	int num, i, ans = 0;
	cin >> num;
	vector<point> p(num);
	map<int, set<int>> d;
	rep(i, num) {
		cin >> p[i].x >> p[i].y;
		d[p[i].x].insert(p[i].y);
	}
	rep(i, num - 1) {
		for (int j = i + 1; j < num; j++) {
			if (Judge(p[i], p[j], d))
				ans++;
		}
	}
	cout << ans / 2 << "\n";
	return 0;
}