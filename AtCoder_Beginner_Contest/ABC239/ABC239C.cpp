#include <iostream>
#include <vector>
#include <string>
#include <list>
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

typedef struct Point_Coordinates {
	int x, y;
	friend Point_Coordinates operator-(const Point_Coordinates& a, const Point_Coordinates& b) {
		return { a.x - b.x, a.y - b.y };
	}
} point;

int main(void) {
	int num, i, j, k = 1, ok = 0;
	vector<point> d = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1} };
	point a, b;
	cin >> a.x >> a.y >> b.x >> b.y;
	rep(j, 2) {
		rep(i, d.size()) {
			point p = { a.x + d[i].x, a.y + d[i].y * k };
			point n = b - p;
			if (max(abs(n.x), abs(n.y)) == 2 and min(abs(n.x), abs(n.y)) == 1) {
				ok = 1;
				break;
			}
		}
		k = -1;
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}