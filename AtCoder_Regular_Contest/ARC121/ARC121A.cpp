#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
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
	int x, y, p;
	friend bool operator<(const Point& l, const Point& r) {
		if (l.x < r.x)
			return true;
		else if (l.x == r.x and l.y < r.y)
			return true;
		return false;
	}
} point;

typedef struct Pair {
	int dist, a, b;
	friend bool operator<(const Pair& l, const Pair& r) {
		return l.dist < r.dist;
	}
} pr;

int main(void) {
	int num, i, ans;
	cin >> num;
	vector<point> a(num), b(num);
	priority_queue<pr> que;
	rep(i, num) {
		cin >> a[i].x >> a[i].y;
		b[i].y = a[i].x;
		b[i].x = a[i].y;
		a[i].p = b[i].p = i;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	rep(i, 2) {
		for (int j = num - 2; j < num; j++) {
			if (i == j)
				continue;
			que.push({ max(abs(a[i].x - a[j].x), abs(a[i].y - a[j].y)), a[i].p, a[j].p });
			que.push({ max(abs(b[i].x - b[j].x), abs(b[i].y - b[j].y)), b[i].p, b[j].p });
		}
	}
	pr p = que.top();
	while (p.a == que.top().a and p.b == que.top().b)
		que.pop();
	cout << que.top().dist << "\n";
	return 0;
}